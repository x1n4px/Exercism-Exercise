module Pangram (isPangram) where
import Data.Char (toLower)

lowercaseLetters :: String
lowercaseLetters = ['a' .. 'z']


isPangram :: String -> Bool
isPangram text = all (`elem` map toLower text) lowercaseLetters
