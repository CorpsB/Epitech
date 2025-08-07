{-
-- EPITECH PROJECT, 2025
-- B-FUN-400-STG-4-1-mypandoc-noe.carabin
-- File description:
-- Main
-}

module Main (main) where
import Control.Exception (try, IOException)
import System.Environment (getArgs)
import System.Exit (exitWith, ExitCode(..))
import System.IO (hPutStrLn, stderr)
import Data.Maybe (fromMaybe)
import Data.List (isSuffixOf)

import Document
import MarkdownParser (markdownToDocument)
import PrintMarkdown (printMarkdown)
import XmlParser (xmlParser)
import ParsingJson (parseJSON)
import WritingXml (writeXml)
import WritingJson (writeJson)

-- |
-- Module      : Main
-- Description : CLI entry point of the mypandoc converter.
-- Handles command-line arguments, reads input files, parses documents
-- from various formats (Markdown, XML, JSON), and writes the converted
-- content to the specified output format.


-- | Configuration for command-line arguments.
-- Each field corresponds to a possible flag passed by the user.
data Conf = Conf
  { i :: Maybe FilePath
  , f :: Maybe String
  , o :: Maybe FilePath
  , e :: Maybe String
  } deriving (Show, Eq)

-- | Default configuration with all fields unset.
defaultConf :: Conf
defaultConf = Conf Nothing Nothing Nothing Nothing

-- | Parses the list of command-line arguments recursively to build a 'Conf'.
-- Returns 'Nothing' if arguments are malformed or incomplete.
param :: Conf -> [String] -> Maybe Conf
param c []             = Just c
param c ("-i":v:xs)    = param (c {i = Just v}) xs
param c ("-f":v:xs)    = param (c {f = Just v}) xs
param c ("-o":v:xs)    = param (c {o = Just v}) xs
param c ("-e":v:xs)    = param (c {e = Just v}) xs
param _ _              = Nothing

-- | Verifies that the configuration has at least:
--   * an input file
--   * a valid output format
--   * and (optionally) a valid input format
checker :: Maybe Conf -> Maybe Conf
checker mc@(Just (Conf (Just _) (Just out) _ inp))
  | out `elem` ["markdown","xml","json"]
  , maybe True (`elem` ["markdown","xml","json"]) inp
  = mc
checker _ = Nothing


-- | Prints the usage instructions to standard error.
usage :: IO ()
usage = hPutStrLn stderr m >>
  hPutStrLn stderr "" >>
  hPutStrLn stderr "\tifile\tpath to the file to convert" >>
  hPutStrLn stderr "\toformat\toutput format (xml, json, markdown)" >>
  hPutStrLn stderr "\tofile\tpath to the output file" >>
  hPutStrLn stderr "\tiformat\tinput format (xml, json, markdown)"
  where m = "USAGE: ./mypandoc -i ifile -f oformat [-o ofile] [-e iformat]\n"

-- | Attempts to read a file safely, handling IO exceptions.
-- Returns an error message if the file is empty or does not exist.
safeRead :: FilePath -> IO (Either String String)
safeRead path = do
  res <- try (readFile path) :: IO (Either IOException String)
  case res of
    Right "" -> exitWith (ExitFailure 84)
    Right txt -> return (Right txt)
    Left  _   -> return (Left "No such file or directory.")

-- | Detects the file format based on its extension.
-- Accepts .md, .markdown, .xml, and .json. Returns an error otherwise.
detectFmt :: FilePath -> Either String String
detectFmt path
  | ".md"      `isSuffixOf` l || ".markdown" `isSuffixOf` l = Right "markdown"
  | ".xml"     `isSuffixOf` l = Right "xml"
  | ".json"    `isSuffixOf` l = Right "json"
  | otherwise = Left "Cannot detect input format (-e missing)."
  where l = map toLower path
        toLower c | 'A'<=c && c<='Z' = toEnum (fromEnum c + 32)
                  | otherwise        = c

-- | Parses a raw string into a 'Document' based on the input format.
-- Returns an error if parsing fails or format is unsupported.
toDocument :: String -> String -> Either String Document
toDocument "markdown" txt = markdownToDocument txt
toDocument "xml" txt = 
  case xmlParser txt of
    Just doc -> Right doc
    Nothing  -> Left "XML parse error"
toDocument "json" txt = parseJSON txt
toDocument _ _           = Left "Unsupported input format."

-- | Renders a 'Document' to a string in the specified output format.
-- Returns an error if the output format is unsupported.
render :: String -> Document -> Either String String
render "markdown" = Right . printMarkdown
render "xml"      = Right . writeXml
render "json"   = Right . writeJson
render _          = const (Left "Unsupported output format.")

-- | Main processing pipeline:
--   1. Determines input format (explicit or inferred)
--   2. Reads the input file
--   3. Parses it into a 'Document'
--   4. Converts it into the output format
--   5. Writes it to file or prints to stdout
-- Any failure during the pipeline causes the program to exit with code 84.
process :: Conf -> IO ()
process conf =
  let inPath = fromMaybe "" (i conf)
      outFmt = fromMaybe "" (f conf)
      getFmt = maybe (detectFmt inPath) Right (e conf)
      bail m = hPutStrLn stderr m >> exitWith (ExitFailure 84)
  in either bail return getFmt >>= \fmt ->
      safeRead inPath >>= either bail return >>= \txt ->
      either bail return (toDocument fmt txt) >>= \doc ->
      either bail return (render outFmt doc) >>= \txtOut ->
      maybe (putStr txtOut) (`writeFile` txtOut) (o conf)

-- | Main entry point of the program.
-- Parses CLI arguments, validates them, and starts the processing pipeline.
main :: IO ()
main = do
  args <- getArgs
  case checker (param defaultConf args) of
    Just conf -> process conf
    Nothing   -> usage >> exitWith (ExitFailure 84)
