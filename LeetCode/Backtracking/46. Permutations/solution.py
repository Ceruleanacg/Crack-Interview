class Solution:
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        results = []

        self.dfs(nums, [], results)

        return results

    def dfs(self, nums, res, results):
        if not nums:
            results.append(res)
            return
        for i in range(len(nums)):
            self.dfs(nums[:i] + nums[i + 1:], res + [nums[i]], results)
