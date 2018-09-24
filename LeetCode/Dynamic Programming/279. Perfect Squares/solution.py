import sys


class Solution:

    dp = [0]

    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        for i in range(1, n + 1):
            res = sys.maxsize
            j = 1
            while j * j <= i:
                res = min(res, self.dp[i - j * j] + 1)
                j += 1
            try:
                self.dp[i] = res
            except IndexError:
                self.dp.append(res)

        return self.dp[n]


s = Solution()

print(s.numSquares(1))
print(s.numSquares(2))
print(s.numSquares(3))
print(s.numSquares(4))
print(s.numSquares(12))
print(s.numSquares(13))

