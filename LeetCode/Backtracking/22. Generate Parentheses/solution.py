class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        results = []
        self.backtrack(n, n, '', results)
        return results

    def backtrack(self, left, right, res, results: list):
        if not left and not right:
            results.append(res)
        if right < left:
            return
        if left:
            self.backtrack(left - 1, right, res + '(', results)
        if right:
            self.backtrack(left, right - 1, res + ')', results)
