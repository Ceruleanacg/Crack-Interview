from typing import List


class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s:
            return ""

        s_len = len(s)

        l_index, r_index, c_max_len = 0, 0, 0

        dp = [[False] * s_len for _ in range(s_len)]

        # for i in range(s_len):
        #     dp[i][i] = True

        for r_bound in range(s_len):
            for l_bound in range(r_bound + 1):
                if r_bound - l_bound == 0:
                    dp[l_bound][r_bound] = True
                elif r_bound - l_bound == 1:
                    dp[l_bound][r_bound] = s[l_bound] == s[r_bound]
                else:
                    dp[l_bound][r_bound] = s[l_bound] == s[r_bound] and dp[l_bound + 1][r_bound - 1]

                if dp[l_bound][r_bound] and c_max_len <= r_bound - l_bound:
                    c_max_len = r_bound - l_bound
                    l_index, r_index = l_bound, r_bound

        return s[l_index:r_index + 1]


print(Solution().longestPalindrome('babad'))