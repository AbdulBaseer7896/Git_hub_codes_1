


class Solution:
    def removeDuplicates(self, nums):

        count = 0
        new_list = []
        for i in nums:
            c = nums.count(i)
            if c>1:
                # new_list.append(i)
                for _ in range(nums.count(i) - 1):
                    count = count +1
                    nums.remove(i)

        for i in range(count):
            nums.append('-')
        print(nums)
        print(count)

obj = Solution()

arr = [1,2]
obj.removeDuplicates(arr)