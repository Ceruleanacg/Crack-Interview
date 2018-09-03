//
//  main.cpp
//  290. Word Pattern [LeetCode]
//
//  Created by Shuyu on 2018/4/10.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

class Solution {
public:
    bool wordPattern(std::string pattern, std::string str) {
        
        str.push_back(' ');
        
        std::map<std::string, char> wordMap;
        std::vector<char> usedPatterns;
        std::string word;
        
        int currentPatternPosition = 0;
        
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] != ' ') {
                word += str[i];
            }
            else {
                if (currentPatternPosition == pattern.length()) {
                    return false;
                }
                
                char currentPattern = pattern[currentPatternPosition];
                
                if (wordMap.find(word) == wordMap.end()) {
                    if (std::find(usedPatterns.begin(), usedPatterns.end(), currentPattern) != usedPatterns.end()) {
                        return false;
                    }
                    wordMap[word] = pattern[currentPatternPosition];
                    usedPatterns.push_back(currentPattern);
                }
                else {
                    if (wordMap[word] != currentPattern) {
                        return false;
                    }
                }
                word = "";
                currentPatternPosition++;
            }
        }
        if (currentPatternPosition != pattern.length()) {
            return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    std::string pattern = "abba";
    std::string str = "dog cat cat dog";
    Solution solve;
    printf("%d\n", solve.wordPattern(pattern, str));
    return 0;
}
