//
//  main.cpp
//  402. Remove K Dights [LeetCode]
//
//  Created by Shuyu on 2018/4/4.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>


class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        // Initialize number stack for removing.
        std::vector<int> stack;
        // Scan num.
        for (int index = 0; index < num.length(); ++index) {
            // a to i.
            int number = num[index] - '0';
            // 1. Stack is not empty.
            // 2. Stack top is bigger than number.
            // 3. k is not 0.
            while (stack.size() && stack[stack.size() - 1] > number && k > 0) {
                // Pop stack top.
                stack.pop_back();
                // Decrase k.
                --k;
            }
            // 1. number is not 0.
            // 2. stack is not empty.
            if (number || stack.size()) {
                stack.push_back(number);
            }
        }
        
        // 1. if k is not 0.
        // 2. stack is not empty.
        
        while (stack.size() && k > 0) {
            stack.pop_back();
            --k;
        }
        
        std::string result = "";
        
        for (int index = 0; index < stack.size(); ++index) {
            result.append(1, '0' + stack[index]);
        }
        
        if (result == "") {
            result = "0";
        }
        
        return result;
    }
};

int main(){
    Solution solve;
    std::string result = solve.removeKdigits("1432219", 3);
    printf("%s\n", result.c_str());
    std::string result2 = solve.removeKdigits("100200", 1);
    printf("%s\n", result2.c_str());
    return 0;
}
