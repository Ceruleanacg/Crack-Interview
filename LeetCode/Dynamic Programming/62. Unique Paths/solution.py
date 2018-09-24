class Solution:

    res = 0

    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        self.res = 0

        dp = [[1 for _ in range(0, n)] for _ in range(0, m)]

        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

        self.res = dp[-1][-1]

        # mat = [[0 for _ in range(0, n)] for _ in range(0, m)]
        # dp  = [[0 for _ in range(0, n)] for _ in range(0, m)]
        # self.dfs(0, 0, mat, dp)
        return self.res

    def dfs(self, i, j, mat, dp):
        if 0 <= i < len(mat) and 0 <= j < len(mat[0]):
            if i == len(mat) - 1 and j == len(mat[0]) - 1:
                self.res += 1
                return

            self.dfs(i + 1, j, mat, dp)
            self.dfs(i, j + 1, mat, dp)


s = Solution()

print(s.uniquePaths(3, 2))
print(s.uniquePaths(7, 3))
