{--
-- EPITECH PROJECT, 2024
-- B-FUN-400-STG-4-1-mypandoc-noe.carabin
-- File description:
-- xml_parser.hs
--}

-- |
-- Module      : XmlParser
-- Description : Parses an XML-formatted string into a 'Document' structure.
-- This parser converts structured XML into the internal Haskell representation used by mypandoc.
module XmlParser (xmlParser) where

import Utils
import Document
import Data.Char (isSpace)
import Data.Maybe (fromMaybe)
import Control.Applicative (many,some,(<|>))

-- | Parses a complete XML document into a 'Document'. Returns 'Nothing' on failure.
xmlParser :: String -> Maybe Document
xmlParser input =
  case runParser xmlDocument input of
    Just (doc, rest) | all isSpace rest -> Just doc
    _                                   -> Nothing

-- | Top-level parser that recognizes the entire <document> structure.
xmlDocument :: Parser Document
xmlDocument = do
  ws
  _    <- string "<document>"
  ws
  hdr  <- parseDocumentHeader
  ws
  body <- parseDocumentBody
  ws
  _    <- string "</document>"
  return $ Document hdr body

-- | Parses author and date tags inside a header, if present.
parseHeaderContent :: Parser (Maybe String, Maybe String)
parseHeaderContent = do
  ws
  authorVal <- parseOptionalTag "author"
  ws
  dateVal   <- parseOptionalTag "date"
  ws
  return (authorVal, dateVal)

-- | Parses the <header> tag and its attributes and children.
parseDocumentHeader :: Parser Header
parseDocumentHeader = do
  _         <- string "<header"
  attrs     <- many parseAttr
  _         <- string ">"
  (authorVal, dateVal) <- parseHeaderContent
  _         <- string "</header>"
  let titleVal = fromMaybe "" (lookup "title" attrs)
  return $ Header titleVal authorVal dateVal

-- | Parses the <body> section and all its child content blocks.
parseDocumentBody :: Parser [Content]
parseDocumentBody = do
  _   <- string "<body>"
  ws
  cs  <- many (parseContentBlock 1)
  ws
  _   <- string "</body>"
  return cs

-- | Parses any block-level content element in the body (section, paragraph, list, or code block).
parseContentBlock :: Int -> Parser Content
parseContentBlock level = ws *> ( parseSectionBlock level
  <|> parseParagraphBlock
  <|> parseCodeBlock
  <|> parseListBlock
  ) <* ws

-- | Adjusts a section title with its level prefix if present.
processTitle :: Int -> Maybe String -> Maybe String
processTitle level titleResult =
  let mbActualTitle = case titleResult of
                        Just "" -> Nothing
                        other   -> other
  in case mbActualTitle of
       Just actualTitle -> Just (show level ++ "|" ++ actualTitle)
       Nothing          -> Nothing

-- | Parses a <section> block and its children recursively.
parseSectionBlock :: Int -> Parser Content
parseSectionBlock level = do
  _        <- string "<section"
  attrs    <- many parseAttr
  _        <- string ">"
  ws
  children <- many (parseContentBlock (level + 1))
  ws
  _        <- string "</section>"
  let titl = processTitle level (lookup "title" attrs)
  return $ Section titl children

-- | Parses a <paragraph> block with inline elements.
parseParagraphBlock :: Parser Content
parseParagraphBlock = do
  _     <- string "<paragraph>"
  elems <- many inlineElement
  _     <- string "</paragraph>"
  return $ Paragraph elems

-- | Parses a <codeblock> block, which contains multiple paragraphs.
parseCodeBlock :: Parser Content
parseCodeBlock = do
  _  <- string "<codeblock>"
  ws
  ps <- many (ws *> parseParagraphBlock <* ws)
  ws
  _  <- string "</codeblock>"
  return $ CodeBlock ps

-- | Parses a <list> block containing multiple items.
parseListBlock :: Parser Content
parseListBlock = do
  _     <- string "<list>"
  ws
  items <- many (ws *> (Item . pure <$> parseParagraphBlock) <* ws)
  ws
  _     <- string "</list>"
  return $ List items

-- | Parses a tag attribute of the form key="value".
parseAttr :: Parser (String,String)
parseAttr = do
  ws
  key <- some (satisfy (\c -> not (isSpace c) && c /= '=' && c /= '>'))
  _   <- parseChar '=' *> parseChar '"'
  val <- many (satisfy (/= '"'))
  _   <- parseChar '"'
  return (key, val)

-- | Parses an optional tag of the form <name>...</name>, or returns Nothing if absent.
parseOptionalTag :: String -> Parser (Maybe String)
parseOptionalTag name =
      (Just <$> (string ("<"++name++">")
               *> many (satisfy (/= '<'))
               <* string ("</"++name++">")))
  <|> pure Nothing

-- | Parses any inline element (bold, italic, code, link, image, text).
inlineElement :: Parser InlineElement
inlineElement =
      boldInline
  <|> italicInline
  <|> codeInline
  <|> linkInline
  <|> imageInline
  <|> textInline

-- | Parses a <bold> inline block.
boldInline :: Parser InlineElement
boldInline = Bold <$> (string "<bold>" *>
  many inlineElement <* string "</bold>")

-- | Parses an <italic> inline block.
italicInline :: Parser InlineElement
italicInline = Italic <$> (string "<italic>" *>
  many inlineElement <* string "</italic>")

-- | Parses a <code> inline block.
codeInline :: Parser InlineElement
codeInline = Code <$> (string "<code>" *>
  many (satisfy (/= '<')) <* string "</code>")

-- | Parses a <link> inline block, with a 'url' attribute.
linkInline :: Parser InlineElement
linkInline = do
  _     <- string "<link" >> ws
  attrs <- many parseAttr
  _     <- string ">"
  inside<- many inlineElement
  _     <- string "</link>"
  let url = fromMaybe "" (lookup "url" attrs)
  return $ Link url inside

-- | Parses an <image> inline block, with a 'url' attribute.
imageInline :: Parser InlineElement
imageInline = do
  _     <- string "<image" >> ws
  attrs <- many parseAttr
  _     <- string ">"
  inside<- many inlineElement
  _     <- string "</image>"
  let url = fromMaybe "" (lookup "url" attrs)
  return $ Image url inside

-- | Parses raw inline text content not enclosed in tags.
textInline :: Parser InlineElement
textInline = Text <$> some (satisfy (/= '<'))
