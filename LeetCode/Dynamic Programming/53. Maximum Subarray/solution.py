# coding=utf-8


class Solution:

    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 边缘条件
        if len(nums) == 0:
            return 0
        # 重叠子问题的解
        dp = [0] * len(nums)
        result = 0
        for index, num in enumerate(nums):
            if index == 0:
                # 初始化问题的解
                dp[0] = num
                result = dp[0]
            else:
                # 比较`当前元素`与`当前元素 + 上一个子问题的解`，选择大的作为`当前子问题的解`
                dp[index] = max(num, num + dp[index - 1])
                # 如果`当前子问题的解`比当前解好，则更新解
                if result < dp[index]:
                    result = dp[index]
        # 返回计算结果
        return result


r = Solution().maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4])

print(r)

