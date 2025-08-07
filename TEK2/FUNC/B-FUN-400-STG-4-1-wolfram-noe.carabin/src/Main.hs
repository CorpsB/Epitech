{-
-- EPITECH PROJECT, 2025
-- B-FUN-400-STG-4-1-wolfram-noe.carabin
-- File description:
-- main
-}

import Text.Read (readMaybe)
import Data.Maybe ()
import System.Environment (getArgs)
import System.Exit

data Conf = Conf {
    rule :: Maybe Int,
    start :: Maybe Int,
    linnes :: Maybe Int,
    window :: Maybe Int, 
    move :: Maybe Int
} deriving (Show, Eq)

defaultConf :: Conf
defaultConf = Conf{rule = Nothing, start = Just 0,
    linnes = Just 2147483647, window = Just 80,
    move = Just 0}

param :: Conf -> [String] -> Maybe Conf
param c [] = Just c
param c ("--rule":x:xs) = readMaybe x >>= \v -> param (c {rule = Just v}) xs
param c ("--start":x:xs) = readMaybe x >>= \v -> param (c {start = Just v}) xs
param c ("--lines":x:xs) = readMaybe x >>= \v -> param (c {linnes = Just v}) xs
param c ("--window":x:xs) =
    readMaybe x >>= \v -> param (c {window = Just v}) xs
param c ("--move":x:xs) = readMaybe x >>= \v -> param (c {move = Just v}) xs
param _ _ = Nothing

firstLine :: [Int]
firstLine = [1]

expandLine :: [Int] -> [Int]
expandLine x = 0 : 0 : x ++ [0, 0]

convert :: Int -> Char
convert 1 = '*'
convert _ = ' '

alignDisplayLine :: [Int] -> Int -> Int -> IO ()
alignDisplayLine line luc moove =
    putStrLn $ replicate offset ' ' ++ map convert slice ++ replicate ri ' '
  where
    halfWin = luc `div` 2
    actualCenter = (length line `div` 2) - moove
    startIndex = max 0 (actualCenter - halfWin)
    slice = take luc (drop startIndex line)
    centerIndexInSlice = actualCenter - startIndex
    offset = max 0 (halfWin - centerIndexInSlice)
    ri = max 0 (luc - offset - length slice)

displayLine :: [Int] -> Int -> Conf -> IO()
displayLine x index (Conf _ (Just begin) _ (Just win) (Just moove))
    | index <= begin = return ()
    | otherwise = alignDisplayLine x win moove
displayLine _ _ _ = return ()

getNbrToBit :: Int -> [Int]
getNbrToBit x = completeBit(reverse (nbrToBit x))

completeBit :: [Int] -> [Int]
completeBit x = replicate (8 - (length x)) 0 ++ x 

nbrToBit :: Int -> [Int]
nbrToBit 0 = [0]
nbrToBit 1 = [1]
nbrToBit x = (mod x 2) : nbrToBit (div x 2)

threeBitToNbr :: [Int] -> Int
threeBitToNbr (x:y:z:_) = (x * (2 * 2) + y * 2 + z)
threeBitToNbr _ = 0

getNeibor :: Int -> [Int] -> [Int]
getNeibor index oldList =
    take 3 (drop (index - 1) oldList)


getNewCell :: [Int] -> [Int] -> Int
getNewCell neibor ruleTable = reverse ruleTable !! (threeBitToNbr neibor)

applyRule :: [Int] -> [Int] -> Int -> [Int]
applyRule oldLine rules index
    | index >= length oldLine - 1 = []
    | otherwise = (getNewCell (getNeibor index oldLine) rules) :
    applyRule oldLine rules (index + 1)

sub :: Int -> Int -> Int -> Int
sub lin star index | index > star = lin - 1
                   | otherwise = lin

lunchWolframe :: [Int] -> [Int] -> Int -> Conf -> IO()
lunchWolframe line rules index params@(Conf b (Just s) (Just lin) c d)
    | lin == 0 = return ()
    | otherwise = displayLine line index params >>
    lunchWolframe (applyRule (expandLine line) rules 1) rules (
        index + 1) (Conf b (Just s) (Just (sub lin s index)) c d)
lunchWolframe _ _ _ _ = return ()

checker :: Maybe Conf -> Maybe Conf
checker Nothing = Nothing
checker (Just (Conf (Just r) (Just s) (Just l) (Just w) o))
    | r < 0 || s < 0 || l < 0 || w < 0 || r > 255 = Nothing
    | otherwise = Just (Conf (Just r) (Just s) (Just l) (Just w) o)
checker _ = Nothing




main :: IO()
main = do
    args <- getArgs
    case checker (param defaultConf args) of
        Just conf@(Conf (Just r) _ _ _ _) ->
            lunchWolframe (expandLine firstLine) (getNbrToBit r) 1 conf
        _ -> putStrLn "Invalid args" >> exitWith (ExitFailure 84)