class Solution:
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right, mid = 0, len(nums) - 1, 0
        while left < right:
            mid = (right + left) // 2
            if nums[mid] < nums[right]:
                right = mid
            else:
                # mid >= right,
                left = mid + 1
        return nums[left]
