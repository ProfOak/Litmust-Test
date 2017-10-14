import Data.List.Split    {- splitOn -}
import System.Environment {- getArgs -}

time2sex :: String -> Int
time2sex time_str =
    sum (zipWith (*) time seconds)
    where
        time = map (read::String->Int) (reverse (splitOn ":" time_str))
        seconds = [1, 60, 3600]

main = do
    args <- getArgs
    let time = args !! 0
    print (time2sex time)

