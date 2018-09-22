class Solution:
    dp = [1, 2]

    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 1:
            return self.dp[n - 1]

        for i in range(2, n):
            i_sqrt = (i + 1) ** 0.5
            if i_sqrt in [float(j) for j in range(1, len(self.dp) + 1)]:
                try:
                    self.dp[i] = 1
                except IndexError:
                    self.dp.append(1)
            else:
                res = min([self.dp[j] + self.dp[len(self.dp) - 1 - j] for j in range(i - 1)])
                try:
                    self.dp[i] = res
                except IndexError:
                    self.dp.append(res)

            print('n = {}, dp: {}'.format(i, self.dp))

        return self.dp[n - 1]


s = Solution()

print(s.numSquares(1))
print(s.numSquares(2))
print(s.numSquares(3))
print(s.numSquares(4))
print(s.numSquares(12))
print(s.numSquares(13))

