{-- 
-- EPITECH PROJECT, 2024
-- B-FUN-400-STG-4-1-mypandoc-noe.carabin
-- File description:
-- AsciidocParser.hs
--}

module AsciidocParser (asciidocToDocument) where

import Utils
import Document
import Data.Char (isSpace)
import Data.List (isPrefixOf, find)
import Control.Monad (guard)
import Control.Applicative

-- Merci pour les fonctions du markdown, Thibaut !
-- (´・ω・)っ由 (cadeau pour Thibaut)
-- ._.)/\(._.   (highfive)

asciidocToDocument :: String -> Either String Document
asciidocToDocument input = do
  let ls       = lines input
  (meta, rest) <- checkHeader ls
  hdr        <- parseHeader meta
  cs         <- checkBody (unlines rest)
  return $ Document hdr cs

checkBody :: String -> Either String [Content]
checkBody bodyStr =
  case runParser (ws *> asciidocParser <* ws <* eof) bodyStr of
    Just (cs, _) -> Right (checkMissingSection cs)
    Nothing      -> Left "asciidoc parsing failed"

asciidocParser :: Parser [Content]
asciidocParser = many contentParser

contentParser :: Parser Content
contentParser = noSpace $
      parseSection
  <|> codeBlockParser
  <|> parseList
  <|> parseParagraph

parseSection :: Parser Content
parseSection = do
  hashes <- some (parseChar '=')
  _ <- parseChar ' '
  titl <- many (satisfy (/= '\n'))
  _ <- parseChar '\n'
  let lvl = length hashes
      tag = show lvl ++ "|" ++ titl
  children <- manyTill contentParser (lookAhead (sectionHeader lvl) <|> eof)
  return $ Section (Just tag) children

sectionHeader :: Int -> Parser ()
sectionHeader lvl = do
  hashes <- some (parseChar '#')
  guard (length hashes <= lvl)
  _ <- parseChar ' '
  return ()

codeBlockParser :: Parser Content
codeBlockParser = do
  _ <- string "[source]"
  _ <- parseChar '\n'
  _ <- string "----"
  _ <- parseChar '\n'
  codeLines <- manyTill (many (satisfy (/= '\n')) <* parseChar '\n')
                         (string "----")
  _ <- optional (parseChar '\n')
  let codeParas = map (\line -> Paragraph [Text line]) codeLines
  return $ CodeBlock codeParas

parseList :: Parser Content
parseList = do
  items <- some $ do
    _ <- string "* "
    text <- many (satisfy (/= '\n'))
    _ <- parseChar '\n'
    let els = case runParser (inlineParser <* eof) text of
                Just (r, _) -> r
                Nothing     -> [Text text]
    return $ Item [Paragraph els]
  return $ List items

parseParagraph :: Parser Content
parseParagraph = do
  notFollowedBy (string "\n")
  line <- many (satisfy (/= '\n'))
  _    <- parseChar '\n'
  let els = case runParser (inlineParser <* eof) line of
              Just (r, _) -> r
              Nothing     -> [Text line]
  return $ Paragraph els

inlineParser :: Parser [InlineElement]
inlineParser = many parseInlineElements

parseInlineElements :: Parser InlineElement
parseInlineElements =
      parseImage
  <|> parseLink
  <|> parseBold
  <|> parseItalic
  <|> parseCode
  <|> parseText

parseBold :: Parser InlineElement
parseBold = do
  _ <- string "*"
  cotent <- manyTill parseInlineElements (string "*")
  return $ Bold cotent

parseItalic :: Parser InlineElement
parseItalic = do
  _ <- string "_"
  cotent <- manyTill parseInlineElements (string "_")
  return $ Italic cotent

parseCode :: Parser InlineElement
parseCode = do
  _ <- string "`"
  code <- many (satisfy (/= '`'))
  _ <- string "`"
  return $ Code code

trim :: String -> String
trim = f . f
  where f = reverse . dropWhile isSpace

parseImage :: Parser InlineElement
parseImage = do
  _ <- string "image:"
  url <- manyTill (satisfy (/= '[')) (char '[')
  _ <- char '['
  alt <- many (satisfy (/= ']'))
  _ <- char ']'
  return $ Image (trim url) [Text alt]

parseLink :: Parser InlineElement
parseLink = do
  label <- manyTill (satisfy (/= '[')) (char '[')
  _ <- char '['
  url <- many (satisfy (/= ']'))
  _ <- char ']'
  return $ Link (trim url) [Text label]

parseText :: Parser InlineElement
parseText = Parser $ \input ->
  case checkNoInlinePrefix input ["*", "`", "_", "[", "image:", "http"] of
    Nothing ->
      case consumeUntilInlineDelimiter input
             ["*", "`", "_", "[", "image:", "http"] of
        (parsed, rest)
          | not (null parsed) -> Just (Text parsed, rest)
          | otherwise         -> Nothing
    Just _ -> Nothing

-- Helper functions (checkNoInlinePrefix and consumeUntilInlineDelimiter) remain the same
checkNoInlinePrefix :: String -> [String] -> Maybe String
checkNoInlinePrefix s prefixes = find (\p -> isPrefixOf p s) prefixes

consumeUntilInlineDelimiter :: String -> [String] -> (String, String)
consumeUntilInlineDelimiter input delimiters = go "" input
  where
    go acc remaining =
      case remaining of
        "" -> (acc, "")
        (c:cs) ->
          if any (`isPrefixOf` remaining) delimiters
          then (acc, remaining)
          else go (acc ++ [c]) cs

--tente d’appliquer p et, si ça réussit, renvoie le résultat sans consommer
--l’entrée (le curseur reste au même endroit).
lookAhead :: Parser a -> Parser a
lookAhead p = Parser $ \input ->
  case runParser p input of
    Just (a, _) -> Just (a, input)
    Nothing     -> Nothing

-- applique p autant de fois que possible jusqu’à ce que end réussisse,
-- puis renvoie la liste des valeurs de chaque p.
manyTill :: Parser a -> Parser end -> Parser [a]
manyTill p end = go
  where
    go = (end >> return []) <|> do
      x  <- p
      xs <- go
      return (x:xs)

--échoue si p réussit (sinon ne consomme rien et réussit silencieusement)
notFollowedBy :: Parser a -> Parser ()
notFollowedBy p = Parser $ \input ->
  case runParser p input of
    Just _  -> Nothing
    Nothing -> Just ((), input)

parseHeader :: [String] -> Either String Header
parseHeader (titleLine : authorLine : dateLine : _) = do
  theTitle <- parseTitle titleLine
  let theAuthor = Just (trim authorLine)
      theDate   = Just (trim dateLine)
  return $ Header theTitle theAuthor theDate
  where
    parseTitle ('=':' ':rest) | not (null rest) = Right (trim rest)
    parseTitle _ = Left "AsciiDoc title must start with '= '"
parseHeader _ = Left "AsciiDoc header must have at least 3 lines"

checkHeader :: [String] -> Either String ([String], [String])
checkHeader [] = Left "Empty file"
checkHeader (l1:ls)
  | "= " `isPrefixOf` l1 =
      let (meta, rest) = break (== "") ls
      in case rest of
           (_ : after) -> Right (l1 : meta, after)
           _           -> Left "Header not properly closed(missing blank line)"
  | otherwise = Left "Header must begin with '= '"

checkMissingSection :: [Content] -> [Content]
checkMissingSection = fillMissingSection 0

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

getLevel :: Int -> String -> Int
getLevel prev t =
  case break (=='|') t of
    (s, '|' : _) | all (`elem` ['0'..'9']) s -> read s
    _                                         -> prev + 1

envelopNothSection :: Int -> Int -> Content -> Content
envelopNothSection prev lvl sec =
  foldr (\_ acc -> Section Nothing [acc]) sec [prev+1 .. lvl-1]
