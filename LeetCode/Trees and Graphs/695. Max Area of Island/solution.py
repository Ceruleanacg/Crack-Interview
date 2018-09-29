class Solution:

    result = 0

    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        self.result = 0

        if not grid or not len(grid[0]):
            return 0

        visited = [[0 for _ in range(len(grid[0]))] for _ in range(len(grid))]

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]:
                    self.dfs(i, j, grid, visited)

        return self.result

    def dfs(self, i, j, grid, visited):
        if 0 <= i < len(grid) and 0 <= j < len(grid[0]):
            if visited[i][j]:
                return 0
            visited[i][j] = 1
            if grid[i][j] == 0:
                return 0
            result = 1
            result += self.dfs(i + 1, j, grid, visited)
            result += self.dfs(i, j + 1, grid, visited)
            result += self.dfs(i - 1, j, grid, visited)
            result += self.dfs(i, j - 1, grid, visited)
            if result > self.result:
                self.result = result
            return result
        else:
            return 0


print(Solution().maxAreaOfIsland([[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]))