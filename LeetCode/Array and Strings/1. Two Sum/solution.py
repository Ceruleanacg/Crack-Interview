class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        num_index_table = {}

        for index, x in enumerate(nums):
            y = target - x
            if y in num_index_table:
                return [num_index_table[y], index]
            else:
                num_index_table[x] = index


r = Solution().twoSum([2, 7, 11, 15], 9)
print(r)