class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """

        if not nums:
            return -1

        peak_idx = -1
        peak_num = float('-inf')

        for idx in range(0, len(nums)):
            if nums[idx] > peak_num:
                peak_num = nums[idx]
                peak_idx = idx
            else:
                break

        if target > nums[peak_idx]:
            return -1

        # target < nums[peak_idx]
        if target >= nums[0]:
            result_idx = self.binary_search(nums[:peak_idx + 1], target, nums)
        else:
            result_idx = self.binary_search(nums[peak_idx + 1:], target, nums)

        return result_idx

    def binary_search(self, nums, target, origin_nums: list):
        if not len(nums):
            return -1
        else:
            mid_idx = len(nums) // 2
            if target > nums[mid_idx]:
                return self.binary_search(nums[mid_idx + 1:], target, origin_nums)
            elif target == nums[mid_idx]:
                return origin_nums.index(target)
            else:
                return self.binary_search(nums[: mid_idx], target, origin_nums)


# print(Solution().search([4, 5, 6, 7, 0, 1, 2], 0))
# print(Solution().search([], 5))
print(Solution().search([1], 1))
