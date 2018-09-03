//
//  main.cpp
//  322. Coin Change [LeetCode]
//
//  Created by Shuyu on 2018/4/9.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> dp;
        for (int i = 0; i <= amount; ++i) {
            dp.push_back(-1);
        }
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (i - coins[j] >= 0 && dp[i - coins[j]] != -1) {
                    if (dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1) {
                        dp[i] = dp[i - coins[j]] + 1;
                    }
                }
            }
        }
        return dp[amount];
    }
};

int main(int argc, const char * argv[]) {
    Solution solve;
    std::vector<int> coins;
    coins.push_back(1);
    coins.push_back(2);
    coins.push_back(5);
    coins.push_back(7);
    coins.push_back(10);
    for (int i = 1; i<= 14; i++){
        printf("dp[%d] = %d\n", i, solve.coinChange(coins, i));
    }
    return 0;
}
