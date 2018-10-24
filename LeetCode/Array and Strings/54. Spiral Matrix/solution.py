class Solution:
    def __init__(self):
        self.i, self.j = 0, 0

    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """

        if not matrix:
            return matrix

        rows = len(matrix)
        cols = len(matrix[0])

        self.i, self.j = 0, 0

        visited = [[0 for _ in range(cols)] for _ in range(rows)]

        res = []

        self.visit(matrix, rows, cols, visited, res)

        return res

    def visit(self, matrix, rows, cols, visited, res):

        continue_visit = False

        while self.j < cols and not visited[self.i][self.j]:
            visited[self.i][self.j] = 1
            res.append(matrix[self.i][self.j])
            self.j += 1
            continue_visit = True

        self.j -= 1
        self.i += 1

        while self.i < rows and not visited[self.i][self.j]:
            visited[self.i][self.j] = 1
            res.append(matrix[self.i][self.j])
            self.i += 1
            continue_visit = True

        self.i -= 1
        self.j -= 1

        while self.j >= 0 and not visited[self.i][self.j]:
            visited[self.i][self.j] = 1
            res.append(matrix[self.i][self.j])
            self.j -= 1
            continue_visit = True

        self.j += 1
        self.i -= 1

        while self.i >= 0 and not visited[self.i][self.j]:
            visited[self.i][self.j] = 1
            res.append(matrix[self.i][self.j])
            self.i -= 1
            continue_visit = True

        self.i += 1
        self.j += 1

        if continue_visit:
            self.visit(matrix, rows, cols, visited, res)


print(Solution().spiralOrder([[1, 2, 3], [4, 5, 6], [7, 8, 9]]))
print(Solution().spiralOrder([[1]]))
print(Solution().spiralOrder([[3], [2]]))
print(Solution().spiralOrder([[2, 3]]))
print(Solution().spiralOrder([]))