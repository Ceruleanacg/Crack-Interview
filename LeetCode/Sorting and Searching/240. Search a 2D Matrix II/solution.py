class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if not matrix or not len(matrix[0]):
            return False

        peak_l_j = 0

        for j in range(len(matrix)):
            if matrix[j][0] <= target:
                peak_l_j = j
            else:
                break

        for j in range(peak_l_j + 1):
            if self.binary_search(matrix[j], target):
                return True

        return False

    def binary_search(self, nums, target):
        if not nums:
            return False

        mid_idx = len(nums) // 2

        if nums[mid_idx] == target:
            return True

        if nums[mid_idx] > target:
            return self.binary_search(nums[:mid_idx], target)
        else:
            return self.binary_search(nums[mid_idx + 1:], target)


print(Solution().searchMatrix([[]], 1))
print(Solution().searchMatrix([[1], [3]], 3))