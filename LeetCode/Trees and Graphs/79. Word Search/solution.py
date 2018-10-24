class Solution:
    def __init__(self):
        self.result = False

    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        self.result = False

        if not board:
            return False

        rows = len(board)
        cols = len(board[0])

        for i in range(rows):
            for j in range(cols):
                self.dfs(i, j, board, word, '')
                if self.result:
                    return True

        return self.result

    def dfs(self, i, j, board, word, pattern):
        if 0 <= i < len(board) and 0 <= j < len(board):
            if len(pattern) > len(word):
                return
            cur_char, cur_target = board[i][j], word[len(pattern) - 1]
            if cur_char != cur_target:
                return
            if pattern == word:
                self.result = True
                return
            else:
                self.dfs(i, j + 1, board, word, pattern + cur_char)
                self.dfs(i + 1, j, board, word, pattern + cur_char)
                self.dfs(i, j - 1, board, word, pattern + cur_char)
                self.dfs(i - 1, j, board, word, pattern + cur_char)
        else:
            return
