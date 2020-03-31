main :: IO ()
main =  do
        putStr "X = "
        x <- readLn
        y <- readLn
        print(x + y)
