{-- 
-- EPITECH PROJECT, 2024
-- B-FUN-400-STG-4-1-mypandoc-noe.carabin
-- File description:
-- PrintMarkdown.hs
--}

-- |
-- Module      : PrintMarkdown
-- Description : Converts a 'Document' back into Markdown-formatted text.
-- Provides functions to serialize a 'Document' structure into valid Markdown.
module PrintMarkdown (printMarkdown, printInFile) where

import Document
import Data.Char (isSpace)
import Data.List (isInfixOf, intercalate)


-- | Converts a 'Document' into a Markdown string.
printMarkdown :: Document -> String
printMarkdown (Document hdr body) =
  printHeader hdr ++ "\n\n" ++ removeBlankBeforeImage (renderBody body)

-- | Renders a list of 'Content' blocks to Markdown text with proper spacing.
renderBody :: [Content] -> String
renderBody []             = ""
renderBody [c]            = stripNL (printContent c)
renderBody (c1:c2:rest)   =
  stripNL (printContent c1)
  ++ separator c1 c2
  ++ renderBody (c2:rest)

-- | Determines the number of newlines to separate two 'Content' blocks.
separator :: Content -> Content -> String
separator (Paragraph _) (Paragraph elems2)
  | any isImage elems2 = "\n"
  | otherwise          = "\n\n"
separator _ _          = "\n\n"

-- | Removes trailing newlines from a string.
stripNL :: String -> String
stripNL = reverse . dropWhile (== '\n') . reverse

-- | Checks if an 'InlineElement' is an image.
isImage :: InlineElement -> Bool
isImage (Image _ _) = True
isImage _           = False

-- | Removes blank lines that precede paragraphs starting with an image.
removeBlankBeforeImage :: String -> String
removeBlankBeforeImage = unlines . go . lines where
  go (l1:"":l2:xs)
    | "![" `isInfixOf` l2 = l1 : l2 : go xs
    | otherwise          = l1 : "" : go (l2:xs)
  go (x:xs) = x : go xs
  go []     = []

-- | Converts a 'Header' into its Markdown metadata representation.
printHeader :: Header -> String
printHeader (Header t ma md) =
  "---\n"
  ++ "title: " ++ t ++ "\n"
  ++ maybe "" (\a -> "author: " ++ a ++ "\n") ma
  ++ maybe "" (\d -> "date: " ++ d ++ "\n") md
  ++ "---"

-- | Converts a 'Content' block to Markdown.
printContent :: Content -> String
printContent (Section (Just t) elems) = printSection t elems
printContent (Section Nothing elems)  = concatMap printContent elems
printContent (Paragraph inls)         = printParagraph inls
printContent (CodeBlock code)         = printCodeBlock code
printContent (List items)             = printList items

-- | Prints a section using the tag format "n|title" and renders its children.
printSection :: String -> [Content] -> String
printSection t elems =
  let (lvl, titleTxt) = parseLevelTitle t
      hashes          = replicate lvl '#'
  in singleLine (hashes ++ " " ++ titleTxt) ++ "\n\n"
     ++ concatMap printContent elems

-- | Extracts section level and title from a tag string like "2|Introduction".
parseLevelTitle :: String -> (Int, String)
parseLevelTitle t =
  case break (=='|') t of
    (n, '|' : txt) | all (`elem` ['0'..'9']) n -> (read n, txt)
    _                                           -> (1, t)

-- | Converts a list of inline elements into a Markdown paragraph.
printParagraph :: [InlineElement] -> String
printParagraph inls = concatMap printInline inls ++ "\n\n"

-- | Renders a code block from a list of paragraphs.
printCodeBlock :: [Content] -> String
printCodeBlock cs = "```\n" ++ intercalate "\n\n" bodyParas ++ "\n```\n"
  where
    paras = [ concatMap extract inls | Paragraph inls <- cs ]
    extract (Text t) = t
    extract _        = ""
    clean s = reverse (dropWhile (== '\n') (reverse s))
    bodyParas = map clean paras

-- | Converts a list of 'Item's into a Markdown unordered list.
printList :: [Item] -> String
printList items = concatMap printListItem items ++ "\n"

-- | Converts a single list item to Markdown syntax.
printListItem :: Item -> String
printListItem (Item elems) =
  concatMap (\e -> "- " ++ removeSpace
    (singleLine (printContent e)) ++ "\n") elems

-- | Converts an inline element to Markdown syntax.
printInline :: InlineElement -> String
printInline (Text txt)       = txt
printInline (Bold elems)     = "**" ++ concatMap printInline elems ++ "**"
printInline (Italic elems)   = "*"  ++ concatMap printInline elems ++ "*"
printInline (Code code)      = "`"  ++ code ++ "`"
printInline (Link url es)    = "["++ concatMap printInline es
  ++ "](" ++ url ++ ")"
printInline (Image url es)   = "![" ++ concatMap printInline es
  ++ "](" ++ url ++ ")"

-- | Cleans a string into a single-line representation by removing extra spaces.
singleLine :: String -> String
singleLine = unwords . words

-- | Removes leading and trailing whitespace from a string.
removeSpace :: String -> String
removeSpace = f . f where f = reverse . dropWhile isSpace

-- | Writes a 'Document' to a file in Markdown format.
printInFile :: FilePath -> Document -> IO ()
printInFile path doc = writeFile path (printMarkdown doc)
