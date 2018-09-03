//
//  main.cpp
//  64. Minimum Path Sum [LeetCode]
//
//  Created by Shuyu on 2018/4/9.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        
        if (grid.size() == 0) {
            return 0;
        }
        
        int row = (int)grid.size();
        int column = (int)grid[0].size();
        
        std::vector<std::vector<int>> dp(row, std::vector<int>(column, 0));
        
        dp[0][0] = grid[0][0];
        
        for (int i = 1; i < column; ++i) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        
        for (int i = 1; i < row; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
            for (int j = 1; j < column; ++j) {
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[row - 1][column - 1];
    }
};

int main(int argc, const char * argv[]) {
    int test[][3] = {{1,3,1}, {1,5,1}, {4,2,1}};
    std::vector<std::vector<int> > grid;
    for (int i = 0; i < 3; i++){
        grid.push_back(std::vector<int>());
        for (int j = 0; j < 3; j++){
            grid[i].push_back(test[i][j]);
        }
    }
    Solution solve;
    printf("%d\n", solve.minPathSum(grid));
    return 0;
}
