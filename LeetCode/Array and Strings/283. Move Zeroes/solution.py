class Solution:
    def moveZeroes(self, nums: list):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        nums.sort(key=lambda x: not x)

        print(nums)


Solution().moveZeroes([0, 1, 0, 3, 12])
Solution().moveZeroes([0, 0, 1])