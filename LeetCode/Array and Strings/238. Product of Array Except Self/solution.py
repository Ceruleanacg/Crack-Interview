class Solution:
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        res = [0] * len(nums)
        res[0] = 1

        nums_count = len(nums)

        cur_product = 1

        for i in range(1, nums_count):
            cur_product *= nums[i - 1]
            res[i] = cur_product

        cur_product = 1

        for i in reversed(range(0, nums_count - 1)):
            cur_product = cur_product * nums[i + 1]
            res[i] *= cur_product

        return res


print(Solution().productExceptSelf([1, 2, 3, 4]))