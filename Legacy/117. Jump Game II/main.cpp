//
//  main.cpp
//  117. Jump Game II
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
     * @return: An integer
     */
    int jump(std::vector<int> &A) {
        if (A.size() < 2) {
            return 0;
        }
        int currentReachablePosition = A[0];
        int currentMaxReachablePosition = A[0];
        int jump_count = 1;
        for (int index = 1; index < A.size(); ++index) {
            if (index > currentReachablePosition) {
                currentReachablePosition = currentMaxReachablePosition;
                jump_count++;
            }
            if (currentMaxReachablePosition < A[index] + index) {
                currentMaxReachablePosition = A[index] + index;
            }
        }
        return jump_count;
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
    printf("%d\n", solve.jump(nums));
    return 0;
}
