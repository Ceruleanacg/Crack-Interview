//
//  main.cpp
//  174. Dungeon Game [LeetCode]
//
//  Created by Shuyu on 2018/4/9.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {
        
        if (dungeon.size() == 0){
            return 0;
        }
        std::vector<std::vector<int>> dp(dungeon.size(), std::vector<int>(dungeon[0].size(), 0));
        
        int row = (int)dungeon.size();
        int col = (int)dungeon[0].size();
        
        dp[row - 1][col - 1] = std::max(1, 1 - dungeon[row - 1][col - 1]);
        
        for (int i = col - 2; i >= 0; i--){
            dp[row - 1][i] = std::max(1, dp[row - 1][i + 1] - dungeon[row - 1][i]);
        }
        for (int i = row - 2; i >= 0; i--){
            dp[i][col - 1] = std::max(1, dp[i + 1][col - 1] - dungeon[i][col - 1]);
        }
        for (int i = row - 2; i >= 0; i--){
            for (int j = col - 2; j >= 0; j--){
                int result = std::min(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = std::max(1, result - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};

int main(int argc, const char * argv[]) {
    int test[][3] = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    std::vector<std::vector<int> > dungeon;
    for (int i = 0; i < 3; i++){
        dungeon.push_back(std::vector<int>());
        for (int j = 0; j < 3; j++){
            dungeon[i].push_back(test[i][j]);
        }
    }
    Solution solve;
    printf("%d\n", solve.calculateMinimumHP(dungeon));
    return 0;
}
