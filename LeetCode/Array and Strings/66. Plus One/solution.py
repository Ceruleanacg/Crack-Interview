class Solution:
    def plusOne(self, digits: list):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        carry = 0

        digits[-1] += 1

        for i in reversed(range(0, len(digits))):
            num = digits[i]
            num += carry
            carry = 0
            if num >= 10:
                carry = 1
            num %= 10
            digits[i] = num

        if carry == 1:
            digits.insert(0, 1)

        return digits


print(Solution().plusOne([1, 2, 3]))
print(Solution().plusOne([9, 9]))
