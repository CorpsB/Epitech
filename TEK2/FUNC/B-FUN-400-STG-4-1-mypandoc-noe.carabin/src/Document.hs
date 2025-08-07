{-- 
-- EPITECH PROJECT, 2024
-- B-FUN-400-STG-4-1-mypandoc-noe.carabin
-- File description:
-- Document.hs
--}

-- |
-- Module      : Document
-- Description : Defines the core data structures used to represent documents.
-- Provides the abstract syntax tree (AST) for representing structured content
-- that can be serialized to or parsed from various formats (Markdown, XML, JSON).
module Document
  ( Document(..)
  , Header(..)
  , Content(..)
  , InlineElement(..)
  , Item(..)
  ) where

-- | Represent the whole document containing a header (metadata)
-- and un body in a list of blocks format (Content).
data Document = Document
    { header :: Header          -- ^ Metadata of the document (title, author, date)
    , content :: [Content]      -- ^ List of blocks (paragraph, sections...)
    } deriving (Show, Eq)


-- | This is the header of the document containing:
-- - A mandatory title
-- - An optionnal author
-- - A optionnal date
data Header = Header
    { title :: String           -- ^ Title of the document (mandatory)
    , author :: Maybe String    -- ^ Author (optionnal)
    , date :: Maybe String      -- ^ Date (optionnal)
    } deriving (Show, Eq)


-- | Represent a content bloc in the body of the document
-- It can be:
-- - A txt paragraph (with inline content)
-- - A section (with sub-blocks)
-- - A code block
-- - A list
data Content
    = Paragraph  [InlineElement]        -- ^ Paragraph containing inline elements
    | Section (Maybe String) [Content]  -- ^ Section with otpionnal title and content
    | CodeBlock [Content]                  -- ^ Block of code
    | List [Item]                       -- ^ List of blocks (each element can contain several content)
    deriving (Show, Eq)


-- | Represent an inline element (in a paragraph):
-- - Plain text
-- - Italic/bold
-- - Code inline
-- - Links
-- - Pictures
data InlineElement
    = Text String                   -- ^ Plain text
    | Italic [InlineElement]        -- ^ Italic text
    | Bold [InlineElement]          -- ^ Bold text
    | Code String                   -- ^ Code inline (ex: `code`)
    | Link String [InlineElement]   -- ^ Link ([text](url))
    | Image String [InlineElement]  -- ^ Picture `!`[alternative text](url)
    deriving (Show, Eq)


-- | List elements, each element can contain several blocks.
newtype Item = Item [Content]
    deriving (Show, Eq)
