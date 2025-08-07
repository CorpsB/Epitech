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
import AsciidocParser (asciidocToDocument)
import PrintMarkdown (printMarkdown)
import XmlParser (xmlParser)
import ParsingJson (parseJSON)
import WritingXml (writeXml)
import WritingJson (writeJson)

data Conf = Conf
  { i :: Maybe FilePath
  , f :: Maybe String
  , o :: Maybe FilePath
  , e :: Maybe String
  } deriving (Show, Eq)

defaultConf :: Conf
defaultConf = Conf Nothing Nothing Nothing Nothing

param :: Conf -> [String] -> Maybe Conf
param c []             = Just c
param c ("-i":v:xs)    = param (c {i = Just v}) xs
param c ("-f":v:xs)    = param (c {f = Just v}) xs
param c ("-o":v:xs)    = param (c {o = Just v}) xs
param c ("-e":v:xs)    = param (c {e = Just v}) xs
param _ _              = Nothing

checker :: Maybe Conf -> Maybe Conf
checker mc@(Just (Conf (Just _) (Just out) _ inp))
  | out `elem` ["markdown","xml","json","adoc"]
  , maybe True (`elem` ["markdown","xml","json","adoc"]) inp
  = mc
checker _ = Nothing

usage :: IO ()
usage = hPutStrLn stderr m >>
  hPutStrLn stderr "" >>
  hPutStrLn stderr "\tifile\tpath to the file to convert" >>
  hPutStrLn stderr "\toformat\toutput format (xml, json, markdown, adoc)" >>
  hPutStrLn stderr "\tofile\tpath to the output file" >>
  hPutStrLn stderr "\tiformat\tinput format (xml, json, markdown)"
  where m = "USAGE: ./mypandoc -i ifile -f oformat [-o ofile] [-e iformat]\n"

safeRead :: FilePath -> IO (Either String String)
safeRead path = do
  res <- try (readFile path) :: IO (Either IOException String)
  case res of
    Right "" -> exitWith (ExitFailure 84)
    Right txt -> return (Right txt)
    Left  _   -> return (Left "No such file or directory.")

detectFmt :: FilePath -> Either String String
detectFmt path
  | ".md"      `isSuffixOf` l || ".markdown" `isSuffixOf` l = Right "markdown"
  | ".xml"     `isSuffixOf` l = Right "xml"
  | ".json"    `isSuffixOf` l = Right "json"
  | ".adoc"    `isSuffixOf` l = Right "adoc"
  | otherwise = Left "Cannot detect input format (-e missing)."
  where l = map toLower path
        toLower c | 'A'<=c && c<='Z' = toEnum (fromEnum c + 32)
                  | otherwise        = c

toDocument :: String -> String -> Either String Document
toDocument "markdown" txt = markdownToDocument txt
toDocument "adoc" txt = asciidocToDocument txt
toDocument "xml" txt = 
  case xmlParser txt of
    Just doc -> Right doc
    Nothing  -> Left "XML parse error"
toDocument "json" txt = parseJSON txt
toDocument _ _           = Left "Unsupported input format."

render :: String -> Document -> Either String String
render "markdown" = Right . printMarkdown
render "xml"      = Right . writeXml
render "json"   = Right . writeJson
render _          = const (Left "Unsupported output format.")

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

main :: IO ()
main = do
  args <- getArgs
  case checker (param defaultConf args) of
    Just conf -> process conf
    Nothing   -> usage >> exitWith (ExitFailure 84)
