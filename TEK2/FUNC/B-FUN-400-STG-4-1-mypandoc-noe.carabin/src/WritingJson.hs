{-
-- EPITECH PROJECT, 2025
-- B-FUN-400-STG-4-1-mypandoc-noe.carabin
-- File description:
-- WritingJson
-}

-- |
-- Module      : WritingJson
-- Description : Converts a 'Document' into its JSON representation.
-- This module provides functions to serialize a 'Document' into JSON format, respecting structure and indentation.
module WritingJson
  ( writeJson
  ) where

import Document (Document(..), Header(..), Content(..), InlineElement(..), Item(..))
import Data.Char (isDigit)

-- | Converts an entire 'Document' into a JSON-formatted string.
writeJson :: Document -> String
writeJson doc = 
  let jsonString = headertoJson doc ++ bodytoJson 1 doc
  in jsonString

-- | Serializes the document header (title, author, date) into JSON.
headertoJson :: Document -> String
headertoJson (Document (Header x y z) _) =
  "{\n" ++ tab 1 ++ "\"header\": {\n" ++
  tab 2 ++ "\"title\": \"" ++ x ++ "\"" ++ aut ++ dat ++ "\n" ++ tab 1 ++ "}"
  where
    aut = case y of
      Just a  -> ",\n" ++ tab 2 ++ "\"author\": \"" ++ a ++ "\""
      Nothing -> ""
    dat = case z of
      Just d  -> ",\n" ++ tab 2 ++ "\"date\": \"" ++ d ++ "\""
      Nothing -> ""

-- | Serializes the body of the document (list of content blocks) into JSON.
bodytoJson :: Int -> Document -> String
bodytoJson tabLevel (Document _ contents) =
  ",\n" ++ tab tabLevel ++ "\"body\": [\n" ++ 
  contentToJson tabLevel contents ++ tab tabLevel ++ "]\n}\n"

-- | Serializes a list of content blocks with appropriate indentation.
contentToJson :: Int -> [Content] -> String
contentToJson _ []     = ""
contentToJson tabLevel [c] = contentElementToJsonNoComma (tabLevel + 1) c
contentToJson tabLevel (c:cs) =
  contentElementToJson (tabLevel + 1) c ++ contentToJson tabLevel cs

-- | Removes the numeric prefix before a pipe (e.g. "1|Title" becomes "Title").
rm_nbr_pipe :: String -> String
rm_nbr_pipe s = case span isDigit s of
    (digits, '|':rest) | not (null digits) -> rest
    _ -> s

-- | Converts a 'Content' block into JSON, ending with a comma.
contentElementToJson :: Int -> Content -> String
contentElementToJson lvl (Paragraph inls) =
  tab lvl ++ "[\n" ++ inlineTextJson lvl inls ++ "\n" ++ tab lvl ++ "],\n"
contentElementToJson lvl (CodeBlock s) = codeBlockToJson lvl s ++ ",\n"
contentElementToJson lvl (Section t c) = sectionToJson lvl t c ++ ",\n"
contentElementToJson lvl (List items) = listToJson lvl items ++ ",\n"

-- | Converts a 'Content' block into JSON, without a trailing comma.
contentElementToJsonNoComma :: Int -> Content -> String
contentElementToJsonNoComma lvl (Paragraph inls) =
  tab lvl ++ "[\n" ++ inlineTextJson lvl inls ++ "\n" ++ tab lvl ++ "]\n"
contentElementToJsonNoComma lvl (CodeBlock s) = codeBlockToJson lvl s ++ "\n"
contentElementToJsonNoComma lvl (Section t c) = sectionToJson lvl t c ++ "\n"
contentElementToJsonNoComma lvl (List items) = listToJson lvl items ++ "\n"

-- | Serializes a code block into JSON.
codeBlockToJson :: Int -> [Content] -> String
codeBlockToJson lvl codeContents =
    let codeTexts = map extractText codeContents
    in 
        tab lvl ++ "{\n" ++
        tab (lvl + 1) ++ "\"codeblock\": [\n" ++
        formatCodeBlock lvl codeTexts ++
        tab (lvl + 1) ++ "]\n" ++ tab lvl ++ "}"

-- | Formats each paragraph inside a code block with proper indentation and comma logic.
formatCodeBlock :: Int -> [String] -> String
formatCodeBlock lvl codeTexts =
    concatMap
        (\(i, text) -> formatCodeElement lvl i (length codeTexts) text)
        (zip [0..] codeTexts)

-- | Formats a single code line with appropriate comma placement.
formatCodeElement :: Int -> Int -> Int -> String -> String
formatCodeElement lvl i len text =
    let textFormatted = tab (lvl + 2) ++ "\"" ++ escJson text ++ "\""
        addComma = if i < len - 1 then ",\n" else "\n"
        formattedText = if i == 0
                        then textFormatted ++ addComma
                        else tab (lvl + 2) ++ "[\n" ++
                             tab (lvl + 3) ++ "\"" ++ escJson text ++ "\"\n" ++
                             tab (lvl + 2) ++ "]" ++ addComma
    in formattedText

-- | Extracts plain text from a 'Content' block, ignoring non-text inline elements.
extractText :: Content -> String
extractText (Paragraph inlineElements) = concatMap (\x -> case x of
    Text t -> t
    _ -> "") inlineElements
extractText _ = ""

-- | Escapes a string to be JSON-safe (quotes, backslashes, control characters).
escJson :: String -> String
escJson = concatMap escapeChar
  where
    escapeChar '"' = "\\\""
    escapeChar '\\' = "\\\\"
    escapeChar '\n' = "\\n"
    escapeChar '\r' = "\\r"
    escapeChar '\t' = "\\t"
    escapeChar c = [c]

-- | Removes the prefix of digits and pipe from a section title (e.g., "2|Title" → "Title").
enleverPrefixe :: String -> String
enleverPrefixe s = 
    let (_, reste) = span isDigit s
    in case reste of
        ('|':xs) -> xs
        _        -> s

-- | Converts a 'Section' block into a JSON object.
sectionToJson :: Int -> Maybe String -> [Content] -> String
sectionToJson lvl titles contents =
  tab lvl ++ "{\n" ++
  tab (lvl + 1) ++ "\"section\": {\n" ++
  rm_nbr_pipe (sectionTitle lvl titles) ++
  tab (lvl + 2) ++ "\"content\": [\n" ++
  contentToJson (lvl + 2) contents ++
  tab (lvl + 2) ++ "]\n" ++
  tab (lvl + 1) ++ "}\n" ++
  tab lvl ++ "}"

-- | Formats the title part of a section for JSON output.
sectionTitle :: Int -> Maybe String -> String
sectionTitle lvl (Just t) =
  tab (lvl + 2) ++ "\"title\": \"" ++ escapeJson(enleverPrefixe(t)) ++ "\",\n"
sectionTitle lvl Nothing =
  tab (lvl + 2) ++ "\"title\": \"\",\n"

-- | Serializes a 'List' block into JSON.
listToJson :: Int -> [Item] -> String
listToJson lvl items =
  tab lvl ++ "{\n" ++
  tab (lvl + 1) ++ "\"list\": [\n" ++
  itemJson lvl items ++
  "\n" ++ tab (lvl + 1) ++ "]\n" ++
  tab lvl ++ "}"

-- | Serializes all list items in JSON format.
itemJson :: Int -> [Item] -> String
itemJson _ [] = ""
itemJson lvl [item] = itemToJson lvl item
itemJson lvl (item:items) = itemToJson lvl item ++ ",\n" ++ itemJson lvl items

-- | Serializes a single list item into JSON.
itemToJson :: Int -> Item -> String
itemToJson lvl (Item [Paragraph inls]) =
  tab (lvl + 2) ++ "[\n" ++
  tab (lvl + 2) ++ removeEscape (inlineJson lvl inls) ++ "\n" ++
  tab (lvl + 2) ++ "]"
itemToJson _ _ = ""

-- | Serializes inline elements into a JSON array.
inlineJson :: Int -> [InlineElement] -> String
inlineJson _ [] = ""
inlineJson _ [el] =
  inlineElementToJsonSimple 0 el
inlineJson _ (el:els) =
  inlineElementToJsonSimple 0 el ++ ",\n" ++
  inlineJson 0 els

-- | Removes backslashes from a string (used before serializing JSON).
removeEscape :: String -> String
removeEscape [] = []
removeEscape ('\\':xs) = removeEscape xs
removeEscape (x:xs) = x : removeEscape xs

-- | Escapes special characters for JSON strings.
escapeJson :: String -> String
escapeJson [] = []
escapeJson ('\\' : xs) = "\\\\" ++ escapeJson xs
escapeJson ('\"' : xs) = "\\\"" ++ escapeJson xs
escapeJson ('\n' : xs) = "\\n" ++ escapeJson xs
escapeJson ('\r' : xs) = "\\r" ++ escapeJson xs
escapeJson ('\t' : xs) = "\\t" ++ escapeJson xs
escapeJson ('[' : xs) = "[" ++ escapeJson xs
escapeJson (']' : xs) = "]" ++ escapeJson xs
escapeJson (x : xs) = x : escapeJson xs

-- | Removes escaped quotes in a string.
removeEscapeQuotes :: String -> String
removeEscapeQuotes [] = []
removeEscapeQuotes ('\\':'\"':xs) = removeEscapeQuotes xs
removeEscapeQuotes (x:xs) = x : removeEscapeQuotes xs

-- | Serializes an 'InlineElement' into a minimal JSON object or string.
inlineElementToJsonSimple :: Int -> InlineElement -> String
inlineElementToJsonSimple lvl (Text s) =
  tab (lvl + 1) ++ "\"" ++ escapeJson s ++ "\""
inlineElementToJsonSimple lvl (Italic [Text s]) =
  singleTagJson lvl "italic" s
inlineElementToJsonSimple lvl (Italic els) =
  listTagJson lvl "italic" els
inlineElementToJsonSimple lvl (Bold [Text s]) =
  singleTagJson lvl "bold" s
inlineElementToJsonSimple lvl (Bold els) =
  listTagJson lvl "bold" els
inlineElementToJsonSimple lvl (Code s) =
  singleTagJson lvl "code" s
inlineElementToJsonSimple lvl (Link url [Text s]) =
  linkOrImageJson lvl "link" url [Text s]
inlineElementToJsonSimple lvl (Link url els) =
  linkOrImageJson lvl "link" url els
inlineElementToJsonSimple lvl (Image url [Text s]) =
  linkOrImageJson lvl "image" url [Text s]
inlineElementToJsonSimple lvl (Image url els) =
  linkOrImageJson lvl "image" url els

-- | Serializes a single-tag inline (like bold, italic, code) with a string.
singleTagJson :: Int -> String -> String -> String
singleTagJson lvl tag s =
  tab (lvl + 1) ++ "{\n" ++
  tab (lvl + 2) ++ "\"" ++ tag ++ "\": \"" ++ escapeJson s ++ "\"\n" ++
  tab (lvl + 1) ++ "}"

-- | Serializes an inline element (bold, italic) that contains a list of inline children.
listTagJson :: Int -> String -> [InlineElement] -> String
listTagJson lvl tag els =
  tab (lvl + 1) ++ "{\n" ++
  tab (lvl + 2) ++ "\"" ++ tag ++ "\": [\n" ++
  inlineTextJson (lvl + 3) els ++ "\n" ++
  tab (lvl + 2) ++ "]\n" ++
  tab (lvl + 1) ++ "}"

-- | Serializes a link or image tag with url and content/alt attributes.
linkOrImageJson :: Int -> String -> String -> [InlineElement] -> String
linkOrImageJson lvl kind url [Text s] =
  tab (lvl + 1) ++ "{\n" ++
  tab (lvl + 2) ++ "\"" ++ kind ++ "\": {\n" ++
  tab (lvl + 3) ++ "\"url\": \"" ++ escapeJson url ++ "\",\n" ++
  tab (lvl + 3) ++ field ++ "[\n" ++
  tab (lvl + 4) ++ "\"" ++ removeEscapeQuotes (escapeJson s) ++ "\"\n" ++
  tab (lvl + 3) ++ "]\n" ++
  tab (lvl + 2) ++ "}\n" ++ tab (lvl + 1) ++ "}"
  where field = if kind == "link" then "\"content\": " else "\"alt\": "
linkOrImageJson lvl kind url els =
  tab (lvl + 1) ++ "{\n" ++
  tab (lvl + 2) ++ "\"" ++ kind ++ "\": {\n" ++
  tab (lvl + 3) ++ "\"url\": \"" ++ escapeJson url ++ "\",\n" ++
  tab (lvl + 3) ++ field ++ "[\n" ++
  inlineTextJson (lvl + 4) els ++ "\n" ++
  tab (lvl + 3) ++ "]\n" ++
  tab (lvl + 2) ++ "}\n" ++ tab (lvl + 1) ++ "}"
  where field = if kind == "link" then "\"content\": " else "\"alt\": "

-- | Serializes inline elements as a JSON array with indentation.
inlineTextJson :: Int -> [InlineElement] -> String
inlineTextJson _ [] = ""
inlineTextJson lvl [el] =
  inlineElementToJsonSimple lvl el
inlineTextJson lvl (el:els) =
  inlineElementToJsonSimple lvl el ++ ",\n" ++
  inlineTextJson lvl els

-- | Creates a string of tabs (4 spaces per level) for indentation.
tab :: Int -> String
tab n = replicate (n * 4) ' '
