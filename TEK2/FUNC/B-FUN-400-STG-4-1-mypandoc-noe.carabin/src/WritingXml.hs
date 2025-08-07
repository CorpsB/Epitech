{-
-- EPITECH PROJECT, 2025
-- B-FUN-400-STG-4-1-mypandoc-noe.carabin
-- File description:
-- WritingXml
-}

-- |
-- Module      : WritingXml
-- Description : Converts a 'Document' into an XML representation.
-- This module provides functionality to serialize structured documents into XML format.
module WritingXml
    ( writeXml
    ) where

import Document (Document(..), Header(..), Content(..), InlineElement(..), Item(..))

-- | Converts an entire 'Document' into an XML-formatted string.
writeXml :: Document -> String
writeXml (Document hdr contents) =
  "<document>\n" ++
  tab 1 ++ writeHeaderXml hdr ++
  tab 1 ++ "<body>\n" ++
  concatMap (writeBodyXml 2) contents ++
  tab 1 ++ "</body>\n" ++
  "</document>"

-- | Converts the 'Header' part of the document into an XML header block.
writeHeaderXml :: Header -> String
writeHeaderXml (Header titles maybeAuthor maybeDate) =
  let titleAttr = if null titles then "" else " title=\"" ++ titles ++ "\""
  in "<header" ++ titleAttr ++ ">\n"
     ++ writeOptionalTags maybeAuthor maybeDate
     ++ tab 1 ++ "</header>\n"

-- | Generates optional XML tags for author and date, if present.
writeOptionalTags :: Maybe String -> Maybe String -> String
writeOptionalTags maybeAuthor maybeDate =
  let authorTag = case maybeAuthor of
        Just authors -> tab 2 ++ "<author>" ++ authors ++ "</author>\n"
        Nothing -> ""
      dateTag = case maybeDate of
        Just dates -> tab 2 ++ "<date>" ++ dates ++ "</date>\n"
        Nothing -> ""
  in authorTag ++ dateTag

-- | Converts each 'Content' block of the body into its corresponding XML representation.
writeBodyXml :: Int -> Content -> String
writeBodyXml a contents = case contents of
  Paragraph str   -> writeParagraph a str
  Section titles s -> writeSectionXml a titles s
  CodeBlock code  -> writeCodeBlock a code
  List items      -> writeList a items

-- | Converts a paragraph with inline elements into XML.
writeParagraph :: Int -> [InlineElement] -> String
writeParagraph a str =
  tab a ++ "<paragraph>" ++ concatMap writeInlineXml str ++ "</paragraph>\n"

-- | Converts a code block (composed of paragraphs) into XML format.
writeCodeBlock :: Int -> [Content] -> String
writeCodeBlock indent codeContents =
    let codeTexts = map extractText codeContents
    in tab indent ++ "<codeblock>\n" ++
       concatMap (generateParagraph indent) (zip [0..] codeTexts) ++
       tab indent ++ "</codeblock>\n"

-- | Converts a paragraph of text from a code block into a single XML line.
generateParagraph :: Int -> (Int, String) -> String
generateParagraph indent (_, text) =
    tab (indent + 1) ++ "<paragraph>" ++ text ++ "</paragraph>\n"

-- | Extracts text from a 'Content' block, ignoring formatting.
extractText :: Content -> String
extractText (Paragraph inlineElements) = concatMap (\inline -> case inline of
    Text t -> t
    _ -> "") inlineElements
extractText _ = ""

-- | Converts a list of items into XML representation.
writeList :: Int -> [Item] -> String
writeList a it =
  tab a ++ "<list>\n" ++ concatMap (wiemXml (a + 1)) it ++ tab a ++ "</list>\n"

-- | Converts a section with a title and contents into XML format.
writeSectionXml :: Int -> Maybe String -> [Content] -> String
writeSectionXml a (Just titleText) section_par =
  let (_, titles) = parseHeaderTitle titleText
      titleAttr = " title=\"" ++ titles ++ "\""
  in tab a ++ "<section" ++ titleAttr ++ ">\n"
     ++ concatMap (writeBodyXml (a + 1)) section_par
     ++ tab a ++ "</section>\n"
writeSectionXml a Nothing section_par =
  tab a ++ "<section title=\"\">\n"
  ++ concatMap (writeBodyXml (a + 1)) section_par
  ++ tab a ++ "</section>\n"

-- | Converts an item in a list into XML by delegating to 'writeBodyXml'.
wiemXml :: Int -> Item -> String
wiemXml a (Item contents) =
  concatMap (writeBodyXml a) contents

-- | Converts an inline element (text, bold, italic, etc.) into its XML representation.
writeInlineXml :: InlineElement -> String
writeInlineXml inline = case inline of
  Text txt       -> txt
  Bold elts      -> wrap "bold" (map writeInlineXml elts)
  Italic elts    -> wrap "italic" (map writeInlineXml elts)
  Code txt       -> wrap "code" [txt]
  Link url elts  -> tagWithAttr "link" "url" url (map writeInlineXml elts)
  Image url elts -> tagWithAttr "image" "url" url (map writeInlineXml elts)

-- | Wraps a list of strings in an XML tag.
wrap :: String -> [String] -> String
wrap tag contents = "<" ++ tag ++ ">" ++ concat contents ++ "</" ++ tag ++ ">"

-- | Wraps a list of strings in a tag with an attribute (e.g., <link url="...">).
tagWithAttr :: String -> String -> String -> [String] -> String
tagWithAttr tag attr val contents =
  "<" ++ tag ++ " " ++ attr ++ "=\"" ++ val ++ "\">"
  ++ concat contents ++ "</" ++ tag ++ ">"

-- | Parses the header title string formatted as "level|title" into a tuple.
parseHeaderTitle :: String -> (Int, String)
parseHeaderTitle headerText =
  case break (== '|') headerText of
    (levelStr, '|':restTitle) -> (read levelStr, restTitle)
    (text, "")                -> (1, text)
    (text, _other)            -> (1, text)

-- | Produces indentation (4 spaces per level).
tab :: Int -> String
tab n = replicate (n * 4) ' '
