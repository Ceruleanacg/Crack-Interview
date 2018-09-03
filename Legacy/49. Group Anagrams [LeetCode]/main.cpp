//
//  main.cpp
//  49. Group Anagrams [LeetCode]
//
//  Created by Shuyu on 2018/4/10.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::map<std::string, std::vector<std::string>> anagramMap;
        std::vector<std::vector<std::string>> results;
        for (int i = 0; i < strs.size(); ++i) {
            std::string str = strs[i];
            std::sort(str.begin(), str.end());
            if (anagramMap.find(str) == anagramMap.end()) {
                std::vector<std::string> anagram;
                anagramMap[str] = anagram;
            }
            anagramMap[str].push_back(strs[i]);
        }
        for (auto anagram : anagramMap) {
            results.push_back(anagram.second);
        }
        return results;
    }
};

int main(int argc, const char * argv[]) {
    std::vector<std::string> strs;
    strs.push_back("eat");
    strs.push_back("tea");
    strs.push_back("tan");
    strs.push_back("ate");
    strs.push_back("nat");
    strs.push_back("bat");
    Solution solve;
    std::vector<std::vector<std::string> > result
    = solve.groupAnagrams(strs);
    for (int i = 0; i < result.size(); i++){
        for (int j = 0; j < result[i].size(); j++){
            printf("[%s]", result[i][j].c_str());
        }
        printf("\n");
    }
    return 0;
}
