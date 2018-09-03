//
//  main.cpp
//  76. Minimum Window Substring [LeetCode]
//
//  Created by Shuyu on 2018/4/10.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string minWindow(std::string originStr, std::string targetStr) {
        
        const int Length = 128;
        
        int originMap[Length] = {0};
        int targetMap[Length] = {0};
        
        std::vector<int> charVec;
        
        for (int i = 0; i < targetStr.length(); ++i) {
            targetMap[targetStr[i]]++;
        }
        
        for (int i = 0; i < Length; ++i) {
            if (targetMap[i] > 0) {
                charVec.push_back(i);
            }
        }
        
        int windowBegin = 0;
        
        std::string result;
        
        for (int i = 0; i < originStr.length(); ++i) {
            originMap[originStr[i]]++;
            while (windowBegin < i) {
                char charBegin = originStr[windowBegin];
                if (targetMap[charBegin] == 0) {
                    windowBegin++;
                }
                else if (originMap[charBegin] > targetMap[charBegin]) {
                    originMap[charBegin]--;
                    windowBegin++;
                }
                else {
                    break;
                }
            }
            if (this->isWindowValid(originMap, targetMap, charVec)) {
                int newWindowLength = i - windowBegin + 1;
                if (result == "" || result.length() > newWindowLength) {
                    result = originStr.substr(windowBegin, newWindowLength);
                }
            }
        }
        return result;
    }
private:
    bool isWindowValid(int originMap[], int targetMap[], std::vector<int> &charVec) {
        for (int i = 0; i < charVec.size(); ++i) {
            char currentChar = charVec[i];
            if (originMap[currentChar] < targetMap[currentChar]) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution solve;
    std::string result = solve.minWindow("ADOBECODEBANC", "ABC");
    printf("%s\n", result.c_str());
    result = solve.minWindow("MADOBCCABEC", "ABCC");
    printf("%s\n", result.c_str());
    result = solve.minWindow("aa", "aa");
    printf("%s\n", result.c_str());
}
