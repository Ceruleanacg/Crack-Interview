//
//  main.cpp
//  413. Arithmetic Slices [LeetCode]
//
//  Created by Shuyu on 2018/4/11.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <numeric>
#include <vector>

class Solution {
public:
    int numberOfArithmeticSlices(std::vector<int>& a) {
        if (a.size() < 3) {
            return 0;
        }
        std::vector<int> dp(a.size(), 0);
        dp[0] = 0;
        dp[1] = 0;
        
        for (int index = 2; index < a.size(); ++index) {
            if (a[index] - a[index - 1] == a[index - 1] - a[index - 2]) {
                dp[index] = dp[index - 1] + 1;
            } else {
                dp[index] = 0;
            }
        }
        
        return std::accumulate(dp.begin(), dp.end(), 0);
    }
};

int main(int argc, const char * argv[]) {
    
    std::vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    
    Solution s;
    auto result = s.numberOfArithmeticSlices(test);
    
    std::cout << result << std::endl;
    
    return 0;
}
