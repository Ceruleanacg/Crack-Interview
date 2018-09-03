//
//  main.cpp
//  198. House Robber [LeetCode]
//
//  Created by Shuyu on 2018/4/9.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        
        std::vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        
        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        
        return dp[nums.size() - 1];
    }
};

int main(int argc, const char * argv[]) {
    Solution solve;
    std::vector<int> nums;
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(6);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(7);
    printf("%d\n", solve.rob(nums));
    return 0;
}
