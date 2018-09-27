class Solution:
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        num_nums = len(nums)

        s, res = 0, 0

        dic = dict()

        for num in nums:
            s += num
            res += dic.get(s - k, 0)


print(Solution().subarraySum([1, 1, 1], 2))