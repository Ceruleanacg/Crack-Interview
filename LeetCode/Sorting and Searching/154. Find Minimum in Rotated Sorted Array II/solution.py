class Solution:
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right, mid = 0, len(nums) - 1, 0
        while left < right:
            mid = (left + right) // 2
            if nums[mid] < nums[right]:
                right = mid
            elif nums[mid] > nums[right]:
                left = mid + 1
            else:
                # mid = right
                if nums[mid] > nums[]:
                left += 1
        return nums[left]
