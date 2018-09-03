class Solution:
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if len(s) == 0:
            return True

        stack = []

        for char in s:
            # 遍历字符串，如果是字母或者数字，转为小写入栈
            if char.isalpha() or char.isalnum():
                stack.append(char.lower())
            # 正逆匹配
        if ''.join(stack) == ''.join(stack[::-1]):
            return True
        else:
            return False


r = Solution().isPalindrome("A man, a plan, a canal: Panama")
print(r)

r = Solution().isPalindrome("race a car")
print(r)

r = Solution().isPalindrome("0P")
print(r)
