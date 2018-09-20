class Solution:
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0

        if len(nums) < 2:
            return nums[0]

        local_max = [0] * len(nums)
        local_max[0] = nums[0]

        local_min = [0] * len(nums)
        local_min[0] = nums[0]

        dp = [0] * len(nums)
        dp[0] = nums[0]

        for i in range(1, len(nums)):
            dp[i] = max(local_max[i - 1] * nums[i],
                        local_min[i - 1] * nums[i],
                        dp[i - 1],
                        nums[i])
            local_max[i] = max(local_max[i - 1] * nums[i], nums[i])
            local_min[i] = min(local_min[i - 1] * nums[i], nums[i])

        return max(dp)


print(Solution().maxProduct([-2, 3, -4]))
print(Solution().maxProduct([-1, -2, -9, -6]))
