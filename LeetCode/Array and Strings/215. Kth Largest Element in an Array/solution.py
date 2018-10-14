import heapq


class Solution:
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        heapq.heapify(nums)
        return heapq.nlargest(k, nums)[-1]


print(Solution().findKthLargest([3, 2, 3, 1, 2, 4, 5, 5, 6], 4))
