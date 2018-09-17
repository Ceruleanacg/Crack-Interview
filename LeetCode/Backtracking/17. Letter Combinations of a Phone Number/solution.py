class Solution:

    digit_char_map = {
        '2': ['a', 'b', 'c'],
        '3': ['d', 'e', 'f'],
        '4': ['g', 'h', 'i'],
        '5': ['j', 'k', 'l'],
        '6': ['m', 'n', 'o'],
        '7': ['p', 'q', 'r', 's'],
        '8': ['t', 'u', 'v'],
        '9': ['w', 'x', 'y', 'z'],
    }

    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if not digits:
            return []

        result = []

        self.dfs(0, digits, "", result)

        return result

    def dfs(self, index, digits, pattern, result):
        if index == len(digits):
            return result.append(pattern)
        else:
            for char in self.digit_char_map[digits[index]]:
                self.dfs(index + 1, digits, pattern + char, result)



