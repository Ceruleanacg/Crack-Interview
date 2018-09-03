//
//  main.cpp
//  187. Repeated DNA Sequences [LeetCode]
//
//  Created by Shuyu on 2018/4/10.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string str) {
        std::map<std::string, int> wordMap;
        std::vector<std::string> results;
        for (int i = 0; i < str.length(); ++i) {
            std::string word = str.substr(i, 10);
            if (wordMap.find(word) != wordMap.end()) {
                wordMap[word] += 1;
            } else {
                wordMap[word] = 1;
            }
        }
        for (auto pair : wordMap) {
            if (pair.second > 1) {
                results.push_back(pair.first);
            }
        }
        return results;
    }
};

int main(int argc, const char * argv[]) {
    std::string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    Solution solve;
    std::vector<std::string> result = solve.findRepeatedDnaSequences(s);
    for (int i = 0; i < result.size(); i++){
        printf("%s\n", result[i].c_str());
    }
    return 0;
}
