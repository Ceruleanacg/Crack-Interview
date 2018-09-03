//
//  main.cpp
//  427. Generate Parentheses
//
//  Created by Shuyu on 2018/4/6.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    /**
     * @param n n pairs
     * @return: All combinations of well-formed parentheses
     */
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> results;
        this->calculateParentesis("", n, n, results);
        return results;
    }
private:
    void calculateParentesis(std::string str,
                             int left,
                             int right,
                             std::vector<std::string> &results) {
        if (left == 0 && right == 0) {
            results.push_back(str);
            return;
        }
        if (left > 0) {
            this->calculateParentesis(str + '(', left - 1, right, results);
        }
        if (left < right) {
            this->calculateParentesis(str + ')', left, right - 1, results);
        }
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    
    auto results = s.generateParenthesis(3);
    
    for (auto str : results) {
        std::cout << str << std::endl;
    }
    
    return 0;
}
