class Solution:
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        res = 0

        num_nums = len(nums)

        dp = [sum(nums[:i + 1]) for i in range(num_nums)]

        for i in range(num_nums):
            if dp[i] == k:
                res += 1
            continue
        return res


print(Solution().subarraySum([1, 1, 1], 2))
