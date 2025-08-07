{-- 
-- EPITECH PROJECT, 2024
-- B-FUN-400-STG-4-1-mypandoc-noe.carabin
-- File description:
-- MarkDownParser.hs
--}

-- |
-- Module      : MarkdownParser
-- Description : Parses Markdown text into a structured 'Document'.
-- Converts Markdown source into a structured internal representation,
-- including support for headers, sections, paragraphs, lists, inline formatting, etc.
module MarkdownParser (markdownToDocument) where

import Utils
import Document
import Data.Char (isSpace)
import Data.List (intercalate, isPrefixOf)
import Control.Monad (guard)
import Control.Applicative

-- | Entry point: parses an entire Markdown document into a 'Document' structure.
-- Returns an error string if the format is invalid.
markdownToDocument :: String -> Either String Document
markdownToDocument input = do
  let ls       = lines input
  (meta, rest) <- checkHeader ls
  hdr        <- parseHeader meta
  cs         <- checkBody (unlines rest)
  return $ Document hdr cs

-- | Parses the body of the Markdown file into a list of 'Content' blocks.
checkBody :: String -> Either String [Content]
checkBody bodyStr =
  case runParser (ws *> markdownParser <* ws <* eof) bodyStr of
    Just (cs, _) -> Right (checkMissingSection cs)
    Nothing      -> Left "Markdown parsing failed"

-- | Top-level parser for document content.
markdownParser :: Parser [Content]
markdownParser = many contentParser

-- | Parses one block of content (section, paragraph, list or code block).
contentParser :: Parser Content
contentParser = noSpace $
      parseSection
  <|> codeBlockParser
  <|> parseList
  <|> parseParagraph

-- | Parses a Markdown section starting with '#' and its children content.
parseSection :: Parser Content
parseSection = do
  hashes <- some (parseChar '#')
  _ <- parseChar ' '
  titl <- many (satisfy (/= '\n'))
  _ <- parseChar '\n'
  let lvl = length hashes
      tag = show lvl ++ "|" ++ titl
  children <- manyTill contentParser (lookAhead (sectionHeader lvl) <|> eof)
  return $ Section (Just tag) children

-- | Helper: detects section headers of equal or higher level (to stop parsing a child section).
sectionHeader :: Int -> Parser ()
sectionHeader lvl = do
  hashes <- some (parseChar '#')
  guard (length hashes <= lvl)
  _ <- parseChar ' '
  return ()

-- | Splits a code block into paragraphs if it contains double newlines.
breakSubstring :: String -> String -> (String, String)
breakSubstring pat str = search "" str
  where
    search acc [] = (acc, [])
    search acc s@(x:xs)
      | pat `isPrefixOf` s = (acc, s)
      | otherwise = search (acc ++ [x]) xs

-- | Parses a Markdown code block delimited by triple backticks.
breakOn :: String -> String -> (String, String)
breakOn delim s =
  let (before, after) = breakSubstring delim s
  in (before, drop (length delim) after)

-- | Parses a Markdown bullet list (lines starting with "- ").
splitCodeParas :: String -> [Content]
splitCodeParas codeStr =
  let chunks = go codeStr
      go s = case breakOn "\n\n" s of
               (x, "")   -> [x]
               (x, rest) -> x : go (drop 2 rest)
  in  [ Paragraph [Text c] | c <- filter (not . all isSpace) chunks ]

-- | Parses a single Markdown paragraph.
codeBlockParser :: Parser Content
codeBlockParser = do
  _         <- string "```"
  _         <- many (satisfy (/= '\n'))
  _         <- parseChar '\n'
  codeLines <- manyTill (many (satisfy (/= '\n')) <* parseChar '\n')
                       (string "```" <* parseChar '\n')
  let fullCode = intercalate "\n" codeLines
  return $ CodeBlock (splitCodeParas fullCode)

-- | Top-level parser for inline content inside a paragraph.
parseList :: Parser Content
parseList = do
  items <- some $ do
    _ <- string "- "
    text <- many (satisfy (/= '\n'))
    _ <- parseChar '\n'
    let els = case runParser (inlineParser <* eof) text of
                Just (r, _) -> r
                Nothing     -> [Text text]
    return $ Item [Paragraph els]
  return $ List items

-- | Parses one inline element (bold, italic, code, link, image, or text).
parseParagraph :: Parser Content
parseParagraph = do
  notFollowedBy (string "\n")
  line <- many (satisfy (/= '\n'))
  _    <- parseChar '\n'
  let els = case runParser (inlineParser <* eof) line of
              Just (r, _) -> r
              Nothing     -> [Text line]
  return $ Paragraph els

-- | Parses a sequence of inline Markdown elements.
inlineParser :: Parser [InlineElement]
inlineParser = many parseInlineElements

-- | Attempts to parse one of several Markdown inline elements.
parseInlineElements :: Parser InlineElement
parseInlineElements =
      parseBold
  <|> parseItalic
  <|> parseCode
  <|> parseImage
  <|> parseLink
  <|> parseText

-- | Parses bold text wrapped in double asterisks (**bold**).
parseBold :: Parser InlineElement
parseBold = do
  _ <- string "**"
  cotent <- manyTill parseInlineElements (string "**")
  return $ Bold cotent

-- | Parses italic text wrapped in single asterisks (*italic*).
parseItalic :: Parser InlineElement
parseItalic = do
  _ <- string "*"
  cotent <- manyTill parseInlineElements (string "*")
  return $ Italic cotent

-- | Parses inline code enclosed in backticks (`code`).
parseCode :: Parser InlineElement
parseCode = do
  _ <- string "`"
  code <- many (satisfy (/= '`'))
  _ <- string "`"
  return $ Code code

-- | Parses a Markdown image: ![alt](url).
-- 'alt' is stored as a Text inside the Image element.
parseImage :: Parser InlineElement
parseImage = do
  _ <- string "!["
  alt <- many (satisfy (/= ']'))
  _ <- string "]("
  url <- many (satisfy (/= ')'))
  _ <- string ")"
  return $ Image url [Text alt]

-- | Parses a Markdown hyperlink: [label](url).
-- 'label' is stored as a Text inside the Link element.
parseLink :: Parser InlineElement
parseLink = do
  _ <- string "["
  label <- many (satisfy (/= ']'))
  _ <- string "]("
  url <- many (satisfy (/= ')'))
  _ <- string ")"
  return $ Link url [Text label]

-- | Parses plain inline text, stopping at formatting symbols.
parseText :: Parser InlineElement
parseText = do
  txt <- some (satisfy (\c -> c /= '*' && c /= '`' && c /= '!' && c /= '['))
  return $ Text txt

-- | Tries to apply parser p without consuming input.
-- Returns the same input untouched if it succeeds.
lookAhead :: Parser a -> Parser a
lookAhead p = Parser $ \input ->
  case runParser p input of
    Just (a, _) -> Just (a, input)
    Nothing     -> Nothing

-- | Repeatedly applies parser p until parser end succeeds.
-- Returns the list of all matched p results.
manyTill :: Parser a -> Parser end -> Parser [a]
manyTill p end = go
  where
    go = (end >> return []) <|> do
      x  <- p
      xs <- go
      return (x:xs)

-- | Fails if parser p succeeds.
-- Otherwise, returns unit without consuming input.
notFollowedBy :: Parser a -> Parser ()
notFollowedBy p = Parser $ \input ->
  case runParser p input of
    Just _  -> Nothing
    Nothing -> Just ((), input)

-- | Looks for a specific metadata key in the header block.
-- Fails if the key is missing or the value is empty.
checkTitle :: String -> [String] -> Either String String
checkTitle key ls =
  let kvs = map parseKeyVal ls
  in case lookup key kvs of
       Just (Just v) | not (all isSpace v) -> Right v
       _ -> Left $ "Key '" ++ key ++ "' missing or empty"

-- | Parses the metadata header block into a 'Header' structure.
-- Extracts 'title' (mandatory), and 'author' and 'date' (optional).
parseHeader :: [String] -> Either String Header
parseHeader ls = do
  titl <- checkTitle "title" ls
  let kvs    = map parseKeyVal ls
      creator = lookup "author" kvs >>= id
      dat   = lookup "date"   kvs >>= id
  return $ Header titl creator dat

-- | Checks that the Markdown input begins with a valid header block.
-- Header must start and end with "---".
checkHeader :: [String] -> Either String ([String], [String])
checkHeader ("---":xs) =
  let (meta, rest) = span (/= "---") xs
  in case rest of
        ("---":after) -> Right (meta, after)
        _             -> Left "Header not closed"
checkHeader _ =
  Left "Header must begin with '---' and end with '---')"

-- | Parses a key-value line from the metadata header.
-- If the value is missing, returns 'Nothing'.
parseKeyVal :: String -> (String, Maybe String)
parseKeyVal line =
  case break (== ':') line of
    (key, ':' : val) -> (removeSpace key, Just (removeSpace val))
    _                -> (line, Nothing)

-- | Removes leading and trailing whitespace from a string.
removeSpace :: String -> String
removeSpace = f . f
  where f = reverse . dropWhile isSpace

-- | Ensures all nested section levels are correctly represented,
-- by adding empty sections if a level is skipped.
checkMissingSection :: [Content] -> [Content]
checkMissingSection = fillMissingSection 0

-- | Recursively ensures section nesting is valid,
-- and wraps sections with missing intermediate levels.
fillMissingSection :: Int -> [Content] -> [Content]
fillMissingSection _    [] = []
fillMissingSection prev (Section (Just t) kids : xs) =
  let lvl     = getLevel prev t
      thisSec = Section (Just t) (fillMissingSection lvl kids)
      wrapped = envelopNothSection prev lvl thisSec
  in  wrapped : fillMissingSection lvl xs
fillMissingSection prev (Section Nothing kids : xs) =
  Section Nothing (fillMissingSection prev kids)
  : fillMissingSection prev xs
fillMissingSection prev (x:xs) =
  x : fillMissingSection prev xs

-- | Extracts the numeric level from a section tag (e.g., "2|Title").
-- If the tag is invalid, defaults to previous level + 1.
getLevel :: Int -> String -> Int
getLevel prev t =
  case break (=='|') t of
    (s, '|' : _) | all (`elem` ['0'..'9']) s -> read s
    _                                         -> prev + 1

-- | Wraps a section into nested empty sections to ensure correct nesting depth.
envelopNothSection :: Int -> Int -> Content -> Content
envelopNothSection prev lvl sec =
  foldr (\_ acc -> Section Nothing [acc]) sec [prev+1 .. lvl-1]
