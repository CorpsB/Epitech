{-
-- EPITECH PROJECT, 2025
-- B-FUN-400-STG-4-1-mypandoc-noe.carabin
-- File description:
-- ParsingJson
-}

-- |
-- Module      : ParsingJson
-- Description : Parses a JSON representation into a structured 'Document'.
-- Converts JSON input into an internal 'Document' structure,
-- including support for metadata headers, sections, paragraphs, lists,
-- code blocks, and inline formatting (bold, italic, code, links, images).
module ParsingJson
  ( parseJSON
  ) where

import Document (Document(..), Header(..), Content(..), InlineElement(..), Item(..))
import Utils
import Control.Applicative ((<|>))

-- | Parses a JSON-encoded string into a 'Document' structure.
-- Fails with an error message if the input is not valid JSON or doesn't match the expected structure.
parseJSON :: String -> Either String Document
parseJSON input =
  case runParser parseJson input of
    Nothing -> Left "Failed parsing"
    Just (json, rest) ->
      if rest == "" then convertToDocument json
      else Left "Parsing Error"

-- | Converts a parsed JSON value into a 'Document' structure,
-- by extracting the header and body fields from a top-level JSON object.
convertToDocument :: JsonValue -> Either String Document
convertToDocument (JsonObject obj) =
  case runParser (parseDocument' obj) "" of
    Just (doc, _) -> Right doc
    Nothing -> Left "Failed to parse to document"
convertToDocument _ = Left "Error"

-- | Parses a list of key-value JSON pairs into a 'Document'.
-- Delegates to 'parseHeader' and 'parseBody'.
parseDocument' :: [(String, JsonValue)] -> Parser Document
parseDocument' obj = do
  headers <- parseHeader obj
  bodys <- parseBody obj
  return $ Document headers bodys

-- | Parses the 'header' field from a JSON object into a 'Header' value.
-- Expects a mandatory 'title', and optional 'author' and 'date'.
parseHeader :: [(String, JsonValue)] -> Parser Header
parseHeader obj =
  case lookup "header" obj of
    Just (JsonObject headerObj) -> do
      titles <- parseMandatoryString "title" headerObj
      authors <- parseOptionalString "author" headerObj
      dates <- parseOptionalString "date" headerObj
      return $ Header titles authors dates
    _ -> Parser $ \_ -> Nothing

-- | Parses the 'body' field from a JSON object into a list of 'Content' blocks.
-- Each block is further parsed according to its type (paragraph, section, etc.).
parseBody :: [(String, JsonValue)] -> Parser [Content]
parseBody obj =
  case lookup "body" obj of
    Just (JsonArray bodyArr) -> parseBodyContent 1 bodyArr
    _ -> Parser $ \_ -> Nothing

-- | Parses a list of JSON values representing content blocks, starting from a given index.
-- Automatically increments the section index where appropriate.
parseBodyContent :: Int -> [JsonValue] -> Parser [Content]
parseBodyContent _ [] = return []
parseBodyContent index (json:rest) = do
  contentss <- parseContent index json
  contents <- parseBodyContent (incrementIndex contentss index) rest
  return (contentss : contents)

-- | Increments the section index only if the content is a section.
incrementIndex :: Content -> Int -> Int
incrementIndex (Section _ _) index = index + 1
incrementIndex _ index = index

-- | Parses a single 'Content' block from a JSON value.
-- Can parse paragraphs (arrays), sections, lists, and code blocks.
parseContent :: Int -> JsonValue -> Parser Content
parseContent index json =
  case json of
    JsonArray paragraphElements ->
      Paragraph <$> mapM parseInlineEl paragraphElements
    JsonObject obj ->
      parseSection index obj <|>
      parseList obj <|>
      parseCodeBlock obj
    _ -> Parser $ \_ -> Nothing

-- | Parses a 'section' JSON object into a 'Section' content block.
-- Extracts its optional title and nested content.
parseSection :: Int -> [(String, JsonValue)] -> Parser Content
parseSection index obj =
  case lookup "section" obj of
    Just (JsonObject sectionObj) -> do
      (titles, contentArr) <- extractSectionData sectionObj
      createSection index titles contentArr
    _ -> Parser $ \_ -> Nothing

-- | Creates a 'Section' content block with a properly formatted title tag and nested content.
-- Automatically attaches the current section level as a prefix to the title.
createSection :: Int -> Maybe String -> [JsonValue] -> Parser Content
createSection index titles contentArr = do
  sectionContent <- mapM (parseContent (index + 1)) contentArr
  let formattedTitle = case titles of
        Just "" -> Nothing
        Just t  -> Just (show index ++ "|" ++ t)
        Nothing -> Just (show index ++ "|")
  return $ Section formattedTitle sectionContent

-- | Extracts the title and content array from a section JSON object.
-- Title is optional, content is mandatory.
extractSectionData :: [(String, JsonValue)] -> Parser (Maybe String, [JsonValue])
extractSectionData sectionObj = do
  titles <- parseOptionalString "title" sectionObj
  contentArr <- parseMandatoryArray "content" sectionObj
  return (titles, contentArr)

-- | Parses a 'list' field from a JSON object into a 'List' content block.
-- Each list item is parsed separately.
parseList :: [(String, JsonValue)] -> Parser Content
parseList obj =
  case lookup "list" obj of
    Just (JsonArray listItems) -> List <$> mapM parseListItem listItems
    _ -> Parser $ \_ -> Nothing

-- | Parses a 'codeblock' field from a JSON object into a 'CodeBlock' content block.
-- Each line is parsed as a paragraph.
parseCodeBlock :: [(String, JsonValue)] -> Parser Content
parseCodeBlock obj =
  case lookup "codeblock" obj of
    Just (JsonArray codeLines) -> do
      codeContents <- mapM parseCodeLine codeLines
      return $ CodeBlock codeContents
    _ -> Parser $ \_ -> Nothing

-- | Parses an individual line inside a code block.
-- The line can be a raw string or an array of inline elements.
parseCodeLine :: JsonValue -> Parser Content
parseCodeLine (JsonArray elements) = Paragraph <$> mapM parseInlineEl elements
parseCodeLine (JsonString str) = return $ Paragraph [Text str]
parseCodeLine _ = Parser $ \_ -> Nothing

-- | Parses a single list item.
-- Items can be arrays of content blocks or plain strings.
parseListItem :: JsonValue -> Parser Item
parseListItem json =
  case json of
    JsonArray [JsonString text] ->
      return $ Item [Paragraph [Text text]]
    JsonArray elements ->
      Item <$> mapM (parseContent 1) elements
    JsonString text ->
      return $ Item [Paragraph [Text text]]
    _ -> Parser $ \_ -> Nothing

-- | Parses an inline element (text, bold, italic, code, link, or image) from a JSON value.
parseInlineEl :: JsonValue -> Parser InlineElement
parseInlineEl (JsonString text) = return $ Text text
parseInlineEl (JsonObject obj) =
  parseBold obj
  <|> parseItalic obj
  <|> parseCode obj
  <|> parseLink obj
  <|> parseImage obj
parseInlineEl _ = Parser $ \_ -> Nothing

-- | Parses a bold inline element, either as a string or an array of nested inline elements.
parseBold :: [(String, JsonValue)] -> Parser InlineElement
parseBold obj =
  case lookup "bold" obj of
    Just (JsonString text) -> return $ Bold [Text text]
    Just (JsonArray elements) -> Bold <$> mapM parseInlineEl elements
    _ -> Parser $ \_ -> Nothing

-- | Parses an italic inline element, either as a string or an array of nested inline elements.
parseItalic :: [(String, JsonValue)] -> Parser InlineElement
parseItalic obj =
  case lookup "italic" obj of
    Just (JsonString text) -> return $ Italic [Text text]
    Just (JsonArray elements) -> Italic <$> mapM parseInlineEl elements
    _ -> Parser $ \_ -> Nothing

-- | Parses an inline code element from a string.
parseCode :: [(String, JsonValue)] -> Parser InlineElement
parseCode obj =
  case lookup "code" obj of
    Just (JsonString text) -> return $ Code text
    _ -> Parser $ \_ -> Nothing

-- | Parses a link element from a JSON object.
-- Expects a 'url' field and optional 'content' field (inline text or array).
parseLink :: [(String, JsonValue)] -> Parser InlineElement
parseLink obj =
  case lookup "link" obj of
    Just (JsonObject linkObj) -> do
      url <- parseMandatoryString "url" linkObj
      contents <- parseOptionalInlineArrayOrString "content" linkObj
      return $ Link url contents
    _ -> Parser $ \_ -> Nothing

-- | Parses an image element from a JSON object.
-- Expects a 'url' field and optional 'alt' text (as inline elements or plain string).
parseImage :: [(String, JsonValue)] -> Parser InlineElement
parseImage obj =
  case lookup "image" obj of
    Just (JsonObject imageObj) -> do
      url <- parseMandatoryString "url" imageObj
      alt <- parseOptionalInlineArrayOrString "alt" imageObj
      return $ Image url alt
    _ -> Parser $ \_ -> Nothing

-- | Parses a mandatory string field from a JSON object.
-- Fails if the key is missing or not a string.
parseMandatoryString :: String -> [(String, JsonValue)] -> Parser String
parseMandatoryString key obj =
  case lookup key obj of
    Just (JsonString s) -> return s
    _ -> Parser $ \_ -> Nothing

-- | Parses an optional string field from a JSON object.
-- Returns 'Nothing' if the field is missing or not a string.
parseOptionalString :: String -> [(String, JsonValue)] -> Parser (Maybe String)
parseOptionalString key obj =
  case lookup key obj of
    Just (JsonString s) -> return (Just s)
    _ -> return Nothing

-- | Parses a mandatory array field from a JSON object.
-- Fails if the field is missing or not an array.
parseMandatoryArray :: String -> [(String, JsonValue)] -> Parser [JsonValue]
parseMandatoryArray key obj =
  case lookup key obj of
    Just (JsonArray arr) -> return arr
    _ -> Parser $ \_ -> Nothing

-- | Parses an optional array of inline elements or a string into a list of inline elements.
-- Used for 'alt' and 'content' fields in links and images.
parseOptionalInlineArrayOrString :: String -> [(String, JsonValue)] -> Parser [InlineElement]
parseOptionalInlineArrayOrString key obj =
  case lookup key obj of
    Just (JsonArray arr) -> mapM parseInlineEl arr
    Just (JsonString s) -> return [Text s]
    _ -> return []
