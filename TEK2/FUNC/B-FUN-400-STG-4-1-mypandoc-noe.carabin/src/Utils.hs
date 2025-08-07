{-
-- EPITECH PROJECT, 2025
-- B-FUN-400-STG-4-1-mypandoc-noe.carabin
-- File description:
-- Utils
-}

-- |
-- Module      : Utils
-- Description : Provides a lightweight parser combinator library and JSON parsing utilities.
-- This module defines the 'Parser' type and combinators for building simple parsers, including a full JSON parser.

module Utils
    ( -- Types
      Parser(..)
    , JsonValue(..)
    
    -- Parsing
    , parseChar
    , digit
    , parseUInt
    , parseInt
    , parseSome
    , parseMany
    , parseTuple
    , parseStringLiteral
    , parseJsonValue
    , parseJsonObject
    , parseJsonArray
    , parseNull
    , parseBool
    , parseNumber
    , parseStringValue
    , parseJson
    , ws
    , noSpace
    , satisfy
    , string
    , escapeString
    , joinWithComma
    , eof
    , sepBy
    , char
    ) where

import Control.Applicative (Alternative(..))
import Data.Char (isDigit, isSpace)

-- | A parser is a function that takes a 'String' and may produce a value and the remaining input.
newtype Parser a = Parser { runParser :: String -> Maybe (a, String) }

instance Functor Parser where
  fmap f (Parser p) = Parser $ \input ->
    case p input of
      Just (a, rest) -> Just (f a, rest)
      Nothing        -> Nothing

instance Applicative Parser where
  pure x = Parser $ \input -> Just (x, input)
  Parser pf <*> Parser pa = Parser $ \input ->
    case pf input of
      Nothing -> Nothing
      Just (f, rest1) ->
        case pa rest1 of
          Nothing -> Nothing
          Just (a, rest2) -> Just (f a, rest2)

instance Alternative Parser where
  empty = Parser $ const Nothing
  Parser p1 <|> Parser p2 = Parser $ \input ->
    p1 input <|> p2 input

instance Monad Parser where
  Parser p >>= f = Parser $ \input ->
    case p input of
      Nothing         -> Nothing
      Just (a, rest)  -> runParser (f a) rest

-- | Parses a single digit character.
digit :: Parser Char
digit = Parser $ \input -> case input of
  [] -> Nothing
  (x:xs) | isDigit x -> Just (x, xs)
         | otherwise -> Nothing

-- | Parses a specific character.
parseChar :: Char -> Parser Char
parseChar c = Parser $ \input ->
  case input of
    (x:xs) | x == c -> Just (x, xs)
    _               -> Nothing

-- | Parses an unsigned integer from a sequence of digits.
parseUInt :: Parser Int
parseUInt = Parser $ \input ->
  case runParser (parseSome digit) input of
    Just (digits, rest) -> Just (read digits, rest)
    Nothing             -> Nothing

-- | Parses a signed integer, handling optional leading minus.
parseInt :: Parser Int
parseInt = (negate <$> (parseChar '-' *> parseUInt)) <|> parseUInt

-- | Parses zero or more repetitions of a parser.
parseMany :: Parser a -> Parser [a]
parseMany p = parseSome p <|> return []

-- | Parses one or more repetitions of a parser.
parseSome :: Parser a -> Parser [a]
parseSome p = (:) <$> p <*> parseMany p

-- | Parses a pair of values inside parentheses, separated by a comma.
parseTuple :: Parser a -> Parser (a, a)
parseTuple p = do
  _  <- parseChar '('
  a1 <- p
  _  <- parseChar ','
  a2 <- p
  _  <- parseChar ')'
  return (a1, a2)

-- | Represents a JSON value.
data JsonValue
  = JsonNull
  | JsonBool Bool
  | JsonNumber Int
  | JsonString String
  | JsonArray [JsonValue]
  | JsonObject [(String, JsonValue)]
  deriving (Show, Eq)

-- | Parses a character satisfying a predicate.
satisfy :: (Char -> Bool) -> Parser Char
satisfy p = Parser $ \input -> case input of
  (x:xs) | p x -> Just (x, xs)
  _            -> Nothing

-- | Parses a literal string.
string :: String -> Parser String
string = traverse char

-- | Joins a list of strings with commas (used for JSON).
joinWithComma :: [String] -> String
joinWithComma = foldr1 (\a b -> a ++ "," ++ b)

-- | Escapes special characters in a string for JSON formatting.
escapeString :: String -> String
escapeString = concatMap escapeChar
  where
    escapeChar '"'  = "\\\""
    escapeChar '\\' = "\\\\"
    escapeChar '\n' = "\\n"
    escapeChar '\r' = "\\r"
    escapeChar '\t' = "\\t"
    escapeChar c    = [c]

-- | Parses and skips all whitespace characters.
ws :: Parser ()
ws = many (satisfy isSpace) >> return ()

-- | Wraps a parser, trimming whitespace before and after.
noSpace :: Parser a -> Parser a
noSpace p = ws *> p <* ws

-- | Parses a JSON object (key-value pairs inside braces).
parseJsonObject :: Parser JsonValue
parseJsonObject = JsonObject <$> noSpace (
  char '{' *> ws *> pairs <* ws <* char '}'
  )
  where
    pair = do
      key <- noSpace parseStringLiteral
      _ <- noSpace (char ':')
      value <- parseJsonValue
      return (key, value)
    pairs = sepBy pair (noSpace (char ','))

-- | Tries to parse any kind of valid JSON value.
parseJsonValue :: Parser JsonValue
parseJsonValue =
      parseNull
  <|> parseBool
  <|> parseNumber
  <|> parseStringValue
  <|> parseJsonArray
  <|> parseJsonObject

-- | Parses the JSON literal 'null'.
parseNull :: Parser JsonValue
parseNull = (\_ -> JsonNull) <$> noSpace (string "null")

-- | Parses the JSON literals 'true' or 'false'.
parseBool :: Parser JsonValue
parseBool = (JsonBool True <$ noSpace (string "true"))
        <|> (JsonBool False <$ noSpace (string "false"))

-- | Parses a JSON number (integer only).
parseNumber :: Parser JsonValue
parseNumber = JsonNumber <$> noSpace parseInt

-- | Parses a string literal (without escaping logic).
parseStringLiteral :: Parser String
parseStringLiteral = char '"' *> content <* char '"'
  where
    content = many (satisfy (/= '"'))

-- | Parses a JSON string.
parseStringValue :: Parser JsonValue
parseStringValue = JsonString <$> noSpace parseStringLiteral

-- | Parses a JSON array of values.
parseJsonArray :: Parser JsonValue
parseJsonArray = JsonArray <$> noSpace (
  char '[' *> ws *> elements <* ws <* char ']'
  )
  where
    elements = sepBy parseJsonValue (noSpace (char ','))

-- | Parses a full JSON document, consuming all whitespace and ensuring EOF.
parseJson :: Parser JsonValue
parseJson = ws *> parseJsonValue <* ws <* eof

-- | Succeeds only at the end of input.
eof :: Parser ()
eof = Parser $ \input -> case input of
  "" -> Just ((), "")
  _  -> Nothing

-- | Parses a list of elements separated by a given separator.
sepBy :: Parser a -> Parser sep -> Parser [a]
sepBy p sep = (:) <$> p <*> many (sep *> p) <|> return []

-- | Parses a single expected character.
char :: Char -> Parser Char
char c = Parser $ \input -> case input of
  (x:xs) | x == c -> Just (x, xs)
  _               -> Nothing
