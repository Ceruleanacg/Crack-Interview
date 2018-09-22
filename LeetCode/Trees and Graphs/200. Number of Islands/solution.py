class Solution:
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if not grid:
            return 0

        if not len(grid[0]):
            return 0

        visited = [[0 for i in range(len(grid[0]))] for j in range(len(grid))]

        result = 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    if self.dfs(i, j, grid, visited) > 0:
                        result += 1

        return result

    def dfs(self, i, j, grid, visited):
        if 0 <= i < len(grid) and 0 <= j < len(grid[0]):
            if visited[i][j] or grid[i][j] == '0':
                return 0
            result = 1

            visited[i][j] = 1

            result += self.dfs(i + 1, j, grid, visited)
            result += self.dfs(i - 1, j, grid, visited)
            result += self.dfs(i, j + 1, grid, visited)
            result += self.dfs(i, j - 1, grid, visited)
            return result
        else:
            return 0


# print(Solution().numIslands([["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]))

