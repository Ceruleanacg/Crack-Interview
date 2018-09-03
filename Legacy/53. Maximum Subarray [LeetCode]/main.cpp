//
//  main.cpp
//  53. Maximum Subarray [LeetCode]
//
//  Created by Shuyu on 2018/4/9.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        
        std::vector<int> dp(nums.size(), 0);
        
        dp[0] = nums[0];
        
        int result = dp[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = std::max(nums[i], dp[i - 1] + nums[i]);
            if (result < dp[i]) {
                result = dp[i];
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution solve;
    std::vector<int> nums;
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);
    printf("%d\n", solve.maxSubArray(nums));
    return 0;
}
