class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if not matrix or not len(matrix[0]):
            return False

        peak_j = 0

        for j in range(len(matrix)):
            if matrix[j][0] <= target:
                peak_j = j
            else:
                break

        result = self.binary_search(matrix[peak_j], target)

        return result

    def binary_search(self, nums, target):
        if not len(nums):
            return False
        mid_idx = len(nums) // 2
        if nums[mid_idx] > target:
            return self.binary_search(nums[: mid_idx], target)
        elif nums[mid_idx] == target:
            return True
        else:
            return self.binary_search(nums[mid_idx + 1:], target)


print(Solution().searchMatrix([[]], 1))
print(Solution().searchMatrix([[1], [3]], 3))
