# https://leetcode.com/problems/string-to-integer-atoi
import re

class Solution:
    def myAtoi(self, st):
        """
        :type str: str
        :rtype: int
        """
        numbers = '0 1 2 3 4 5 6 7 8 9'.split()
        signs = "- +".split()
        st = st.strip()
        if not st or (st[0] not in numbers and st[0] not in signs):
            return 0
        nums = re.findall('\d*\.?\d+', st)
        if not nums:
            return 0
        if len(nums) > 1:
            nums = nums[0]
        print(nums)

        # index of number
        numind = st.index(''.join(nums))

        # check if + or - before this
        sign_1 = 0
        sign_2 = 0
        try:
            signind = st.index('+')
            if signind < numind and numind - signind == 1:
                sign_1 = st[signind]
            elif signind < numind and numind - signind != 1:
                return 0
            elif signind > numind:
                pass
        except:
            pass

        try:
            signind = st.index('-')
            if signind < numind and numind - signind == 1:
                sign_2 = st[signind]
            elif signind < numind and numind - signind != 1:
                return 0
            elif signind > numind:
                pass
        except:
            pass

        if sign_1 == "+" and sign_2 == "-":
            return 0
        elif sign_1 == '+':
            st = sign_1 + ''.join(nums)
        elif sign_2 == '-':
            st = sign_2 + ''.join(nums)
        else:
            st = ''.join(nums)

        try:
            if int(float(st)) < -2 ** 31:
                return -2 ** 31
            elif int(float(st)) > (2 ** 31) - 1:
                return (2 ** 31) - 1
            else:
                return int(float(st))
        except:
            if st[numind] == '-':
                return -2 ** 31
            else:
                return (2 ** 31) - 1