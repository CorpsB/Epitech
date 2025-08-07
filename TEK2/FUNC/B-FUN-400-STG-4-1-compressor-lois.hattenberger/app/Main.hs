{-
-- EPITECH PROJECT, 2025
-- B-FUN-400-STG-4-1-compressor-lois.hattenberger
-- File description:
-- uf Main
-}

import System.Environment (getArgs)
import System.Exit (exitWith, ExitCode(..))
import Text.Read (readMaybe)
import System.Random (newStdGen, StdGen, randomRs)

data Conf = Conf {
    nbr :: Maybe Int,
    ll :: Maybe Float,
    ff :: Maybe String
} deriving (Show, Eq)

data Pixel = Pixel {
    position :: Maybe (Int, Int),
    rgb :: Maybe (Int, Int, Int)
} deriving (Show, Eq)

data Cluster = Cluster Pixel [Pixel]

completeCluster :: [Pixel] -> [Cluster]
completeCluster [] = []
completeCluster (x:xs) = Cluster x [] : completeCluster xs

takeRandom :: Int -> [a] -> StdGen -> ([a], StdGen)
takeRandom n list gen =
    let indices = take n $ randomRs (0, length list - 1) gen
    in ([list !! i | i <- indices], gen)

selectRandomPixels :: Int -> [Pixel] -> StdGen -> ([Cluster], StdGen)
selectRandomPixels n list gen =
    let (selectedPixels, newGen) = takeRandom n list gen
    in (completeCluster selectedPixels, newGen)

newLong :: Pixel -> Pixel -> Float
newLong p1@(Pixel _ (Just (r1, g1, b1))) p2@(Pixel _ (Just (r2, g2, b2))) =
    sqrt (fromIntegral ((r1 - r2) ^ (2 :: Int) + (g1 - g2) ^ (2 :: Int) +
    (b1 - b2) ^ (2 :: Int)))
newLong _ _ = error "newLong error"

findLessLong :: [Cluster] -> Pixel -> Float -> Int -> Int -> Int
findLessLong [] _ _ _ bestIndex = bestIndex
findLessLong ((Cluster centroid _):xs) actual lessDist index bestIndex
    | newLong centroid actual < lessDist =
        findLessLong xs actual (newLong centroid actual) (index + 1) index 
    | otherwise  = findLessLong xs actual lessDist (index + 1) bestIndex

assignPixelToCluster :: [Cluster] -> Int -> Pixel -> [Cluster]
assignPixelToCluster (Cluster centroid pixelList : xs) 0 pix =
    Cluster centroid (pix : pixelList) : xs
assignPixelToCluster (x:xs) n pix = x : assignPixelToCluster xs (n - 1) pix

addClusterCaller :: Pixel -> [Cluster] -> [Cluster]
addClusterCaller pixel cluster =
    assignPixelToCluster cluster (findLessLong cluster pixel 442.0 0 0 ) pixel

findMed :: [Pixel] -> (Int, Int, Int, Int) -> (Int, Int, Int)
findMed [] (r, g, b, 0) = (r, g, b)
findMed [] (r, g, b, i) = (r `div` i, g `div` i, b `div` i)
findMed (Pixel _ (Just (rp, gp, bp)):xs) (r, g, b, i) =
    findMed xs (r + rp, g + gp, b + bp, i + 1)

setNewCentroide :: [Cluster] -> [Cluster]
setNewCentroide [] = []
setNewCentroide (oldc@(Cluster _ []):xs) = oldc : setNewCentroide xs
setNewCentroide (Cluster _ pixelList : xs) =
    Cluster (Pixel (Just (-1, -1)) (Just (findMed pixelList (0, 0, 0, 0)))) []
    : setNewCentroide xs

isConverg :: Float -> [Cluster] -> [Cluster] -> Bool
isConverg _ [] [] = True
isConverg _ [] _  = False
isConverg _ _  [] = False
isConverg eps oldClusters newClusters =
    let totalDist = sum $ zipWith distanceOf oldClusters newClusters
    in totalDist < eps
  where
    distanceOf (Cluster oldCent _) (Cluster newCent _) =
        newLong oldCent newCent

launchLoop :: Float -> [Pixel] -> [Cluster] -> [Cluster]
launchLoop l pixelList clusters
    | isConverg l clusters newClusters = newClusters
    | otherwise = launchLoop l pixelList newClusters
  where
    newClusters =
        setNewCentroide (foldl (flip addClusterCaller) clusters pixelList)

launchCompressor :: Conf -> [Pixel] -> IO [Cluster]
launchCompressor (Conf (Just n) (Just l) _) pixelList = do
    gen <- newStdGen
    let (initialClusters, _) = selectRandomPixels n pixelList gen
        finalCentroids  = launchLoop l pixelList initialClusters
        finalAssigned = foldl (flip addClusterCaller) finalCentroids pixelList
    return finalAssigned

printPixelList :: [Pixel] -> IO ()
printPixelList [] = return ()
printPixelList ((Pixel (Just p) (Just color)):xs) =
    putStrLn (show p ++ " " ++ show color) >> printPixelList xs

printResult :: [Cluster] -> IO ()
printResult [] = return () 
printResult (Cluster (Pixel _ (Just color)) pixelList : xs) =
    putStrLn "--" >>
    putStrLn (show color) >>
    putStrLn "-" >>
    printPixelList pixelList >>
    printResult xs
printResult (_:xs) = printResult xs

getPos :: String -> Maybe (Int, Int)
getPos str = case words str of
    (posStr:_) -> readMaybe posStr
    _ -> Nothing

getRgb :: String -> Maybe (Int, Int, Int)
getRgb str = case words str of
    (_:rgbStr:_) -> readMaybe rgbStr
    _ -> Nothing

defPixel :: String -> Pixel
defPixel str = Pixel { position = getPos str, rgb = getRgb str}

parse :: String -> [Pixel]
parse s = map defPixel (lines s)

readFunc :: Conf -> IO [Pixel]
readFunc (Conf _ _ (Just f)) = do
    fileContent <- readFile f
    return (parse fileContent)

defaultConf :: Conf
defaultConf = Conf { nbr = Nothing, ll = Nothing, ff = Nothing }

param :: Conf -> [String] -> Maybe Conf
param c [] = Just c
param c ("-n":x:xs) = readMaybe x >>= \v -> param (c {nbr = Just v}) xs
param c ("-l":x:xs) = readMaybe x >>= \v -> param (c {ll = Just v}) xs
param c ("-f":x:xs) = param (c {ff = Just x}) xs
param _ _ = Nothing

main :: IO ()
main = do
    args <- getArgs
    case param defaultConf args of
        Just (Conf Nothing Nothing Nothing) -> 
            putStrLn "You're so bad" >> exitWith (ExitFailure 84)
        Just conf -> do {
            pixels <- readFunc conf; clusters <- launchCompressor conf pixels;
            printResult clusters }
        Nothing -> 
            putStrLn "You're so bad" >> exitWith (ExitFailure 84)