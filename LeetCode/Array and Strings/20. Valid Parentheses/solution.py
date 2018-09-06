class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if not s:
            return True

        stack = []

        for char in s:
            if char == '{' or char == '[' or char == '(':
                stack.append(char)
            else:
                try:
                    c = stack.pop()
                    if char == '}':
                        if c != '{':
                            return False
                    elif char == ']':
                        if c != '[':
                            return False
                    elif char == ')':
                        if c != '(':
                            return False
                except IndexError:
                    return False

        if len(stack) > 0:
            return False
        else:
            return True




print(Solution().isValid('()'))