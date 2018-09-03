//
//  main.cpp
//  120. Triangle [LeetCode]
//
//  Created by Shuyu on 2018/4/9.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        
        if (!triangle.size()) {
            return 0;
        }
        
        std::vector<std::vector<int>> dp;
        
        for (int i = 0; i < triangle.size(); ++i) {
            dp.push_back(std::vector<int>());
            for (int j = 0; j < triangle.size(); ++j) {
                dp[i].push_back(0);
            }
        }
        
        for (int i = 0; i < dp.size(); ++i) {
            dp[dp.size() - 1][i] = triangle[dp.size() - 1][i];
        }
        
        for (int i = (int)dp.size() - 2; i >= 0 ; --i) {
            for (int j = 0; j < dp[i].size(); ++j) {
                dp[i][j] = std::min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }
        
        return dp[0][0];
    }
};

int main(int argc, const char * argv[]) {
    std::vector<std::vector<int> > triangle;
    int test[][10] = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    for (int i = 0; i < 4; i++){
        triangle.push_back(std::vector<int>());
        for (int j = 0; j < i + 1; j++){
            triangle[i].push_back(test[i][j]);
        }
    }
    Solution solve;
    printf("%d\n", solve.minimumTotal(triangle));
    return 0;
}
