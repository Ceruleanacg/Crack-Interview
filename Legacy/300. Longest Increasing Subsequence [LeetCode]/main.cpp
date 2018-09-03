//
//  main.cpp
//  300. Longest Increasing Subsequence [LeetCode]
//
//  Created by Shuyu on 2018/4/9.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        
        if (nums.size() == 0) {
            return 0;
        }
        
        int result = 1;
        
        std::vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        
        for (int i = 1; i < dp.size(); ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
                if (result < dp[i]) {
                    result = dp[i];
                }
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    int test[] = {10, 9, 2, 5, 3, 7, 101, 18};
    std::vector<int> nums;
    for (int i = 0; i < 8; i++){
        nums.push_back(test[i]);
    }
    Solution solve;
    printf("%d\n", solve.lengthOfLIS(nums));
    return 0;
}
