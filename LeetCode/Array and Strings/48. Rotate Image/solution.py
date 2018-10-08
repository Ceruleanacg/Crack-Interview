class Solution:
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        # 1. Transform matrix.
        for i in range(len(matrix)):
            for j in range(i, len(matrix[0])):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

        num_row, num_col = len(matrix), len(matrix[0])
        # 2. Flip matrix.
        for i in range(len(matrix)):
            for j in range(len(matrix[0]) // 2):
                matrix[i][j], matrix[i][num_col - j - 1] = matrix[i][num_col - j - 1], matrix[i][j]


Solution().rotate([[1, 2, 3], [4, 5, 6], [7, 8, 9]],)