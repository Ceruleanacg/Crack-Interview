//
//  main.cpp
//  33. N-Queens
//
//  Created by Shuyu on 2018/4/6.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    /*
     * @param n: The number of queens
     * @return: All distinct solutions
     */
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::vector<int>> map;
        std::vector<std::string> locations;
        
        for (int index = 0; index < n; index++) {
            map.push_back(std::vector<int>());
            for (int i = 0; i < n; ++i) {
                map[index].push_back(0);
            }
            locations.push_back("");
            locations[index].append(n, '.');
        }
        
        this->solve(0, n, locations, result, map);
        
        return result;
    }
private:
    
    void solve(int row,
               int n,
               std::vector<std::string> &locations,
               std::vector<std::vector<std::string>> &result,
               std::vector<std::vector<int>> &map) {
        if (row == n) {
            return result.push_back(locations);
        }
        for (int col = 0; col < n; ++col) {
            if (map[row][col] == 0) {
                std::vector<std::vector<int>> mapCopy = map;
                locations[row][col] = 'Q';
                this->setQueen(row, col, map);
                this->solve(row + 1, n, locations, result, map);
                map = mapCopy;
                locations[row][col] = '.';
            }
        }
    }
    
    void setQueen(int x, int y, std::vector<std::vector<int>> &map) {
        static const int dx[] = {-1, 1,  0, 0, -1, -1,  1, 1};
        static const int dy[] = { 0, 0, -1, 1, -1,  1, -1, 1};
        map[x][y] = 1;
        for (int i = 1; i < map.size(); ++i) {
            for (int j = 0; j < 8; ++j) {
                int newX = x + i * dx[j];
                int newY = y + i * dy[j];
                if (newX >= 0 && newX < map.size() && newY >=0 && newY < map.size()) {
                    map[newX][newY] = 1;
                }
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    
    std::vector<std::vector<std::string>> result;
    
    Solution s;
    
    result = s.solveNQueens(4);
    
    for (auto i = 0; i < result.size(); ++i) {
        std::cout << i << std::endl;
        for (auto j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j] << std::endl;
        }
    }
    
    return 0;
}
