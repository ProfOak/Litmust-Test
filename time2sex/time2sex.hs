import System.Environment

main = do
    let args = ["12","34", "56"]
    map read args :: [Int]
    putStrLn show args :: String

