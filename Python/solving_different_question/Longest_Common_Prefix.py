
import pandas as pd
import numpy as np

from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if strs == [""]:
            return ""
        elif len(strs) == 1:
            return strs[0]  # Return the only string in the list
        min_str = min(strs, key=len)
        print(min_str)
        for i, char in enumerate(min_str):
            print("this is i = " , i , "This is the char = " , char)
            if any(s[i] != char for s in strs):
                return min_str[:i]

obj = Solution()

str = ['xyzaa' , 'xyzbb' , 'xyzcc']
str = ["a"]
print(obj.longestCommonPrefix(str))