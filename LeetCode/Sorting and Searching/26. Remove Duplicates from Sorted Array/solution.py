# https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0

        index_tail = 0

        for index, num in enumerate(nums):
            if nums[index_tail] != num:
                index_tail += 1
                nums[index_tail] = num
    
        return index_tail + 1