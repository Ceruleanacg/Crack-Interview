class Solution:
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0

        dp = [0] * len(nums)
        dp[0] = 1

        result = 1

        for i in range(len(nums)):
            for j in range(i):
                if nums[i] > nums[j]:
                    result = max(result, dp[j])
            dp[i] = result + 1
            result = max(result, dp[i])

        return result


print(Solution().lengthOfLIS([-2, -1]))

