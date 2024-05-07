class Solution:
    def isPalindrome(self, x: int) -> bool:
        l = str(x)
        num = x
        length = len(l)
        print(length)
        if x <0:
            print("its is not a palindrome")
            return False
        arr = []
        for i in range(length):
            end = int(x % 10)
            arr.append(end)
            x = int(x /10)
        join_int = int(''.join(map(str, arr)))
        if join_int  == num:
            print("its is ")
            return True
        else:
            print("its is not")
            return False

obj = Solution()

obj.isPalindrome(121)
