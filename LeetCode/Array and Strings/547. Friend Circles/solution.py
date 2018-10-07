class Solution:
    def findCircleNum(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """

        num_row = len(M)

        visited = [0 for _ in range(num_row)]

        res = 0

        for row in range(num_row):
            if visited[row]:
                continue
            visited[row] = 1
            stack = [row]
            while stack:
                i = stack.pop()
                for j in range(num_row):
                    if not visited[j] and M[i][j] == 1:
                        visited[j] = 1
                        stack.append(j)
            res += 1
        return res
