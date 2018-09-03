//
//  main.cpp
//  116. Jump Game
//
//  Created by Shuyu on 2018/4/5.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <vector>

class Solution {
public:
    /**
     * @param A A list of integers
     * @return: A boolean
     */
    bool canJump(std::vector<int> &A) {
        std::vector<int> indices;
        for (int index = 0; index < A.size(); ++index) {
            indices.push_back(index + A[index]);
        }
        int currentPosition = 0;
        int currentMaxPositon = indices[0];
        while (currentPosition < indices.size() && currentPosition <= currentMaxPositon) {
            if (currentMaxPositon < indices[currentPosition]) {
                currentMaxPositon = indices[currentPosition];
            }
            ++currentPosition;
        }
        if (currentPosition == indices.size()) {
            return true;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    
    std::vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(4);
    Solution solve;
    printf("%d\n", solve.canJump(nums));
    return 0;
    
}
