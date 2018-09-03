//
//  main.cpp
//  3. Longest Substring Without Repeating Characters [LeetCode]
//
//  Created by Shuyu on 2018/4/10.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int lengthOfLongestSubstring(std::string str) {
        int begin = 0;
        int result = 0;
        std::string word = "";
        int charMap[128] = {0};
        for (int i = 0; i < str.length(); ++i) {
            char currentChar = str[i];
            charMap[currentChar]++;
            if (charMap[currentChar] == 1) {
                word += currentChar;
                if (result < word.length()) {
                    result = (int)word.length();
                }
            }
            else {
                while (begin < i && charMap[currentChar] > 1) {
                    charMap[str[begin]]--;
                    begin++;
                }
                word = "";
                for (int j = begin; j <= i; ++j) {
                    word += str[j];
                }
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    std::string s = "abcbadab";
    Solution solve;
    printf("%d\n", solve.lengthOfLongestSubstring(s));
    return 0;
}
