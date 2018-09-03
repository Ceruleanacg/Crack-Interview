//
//  main.cpp
//  409. Longest Palindrome [LeetCode]
//
//  Created by Shuyu on 2018/4/10.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int longestPalindrome(std::string s) {
        int charMap[128] = {0};
        int result = 0;
        int centerFlag = 0;
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            charMap[ch]++;
        }
        for (int i = 0; i < 128; ++i) {
            if (charMap[i] % 2 == 0) {
                result += charMap[i];
            }
            else {
                result += charMap[i] - 1;
                centerFlag = 1;
            }
        }
        return result + centerFlag;
    }
};

int main(int argc, const char * argv[]) {
    std::string s = "abccccddaa";
    Solution solve;
    printf("%d\n", solve.longestPalindrome(s));
    return 0;
}
