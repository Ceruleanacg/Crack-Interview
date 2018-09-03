//
//  main.cpp
//  376. Wiggle Subsequence [LeetCode]
//
//  Created by Shuyu on 2018/4/4.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int wiggleMaxLength(std::vector<int>& nums) {
        // If nums length is less 2, it's wiggle and max wiggle length is 2.
        if (nums.size() < 2) {
            return (int)nums.size();
        }
        // Declare 3 states.
        static const int BEGIN = 0;
        static const int UP = 1;
        static const int DOWN = 2;
        
        // Initialize state.
        int STATE = BEGIN;
        
        // Initialzie least sequence length.
        int max_length = 1;
        
        // Scan sequences.
        for (int index = 1; index < nums.size(); ++index) {
            switch (STATE) {
                case BEGIN:
                    if (nums[index - 1] < nums[index]) {
                        STATE = UP;
                        ++max_length;
                    } else if (nums[index - 1] > nums[index]) {
                        STATE = DOWN;
                        ++max_length;
                    }
                    break;
                case UP:
                    if (nums[index - 1] > nums[index]) {
                        STATE = DOWN;
                        ++max_length;
                    }
                    break;
                case DOWN:
                    if (nums[index - 1] < nums[index]) {
                        STATE = UP;
                        ++max_length;
                    }
                    break;
                default:
                    break;
            }
        }
        return max_length;
    }
};

int main(int argc, const char * argv[]) {
    
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(17);
    nums.push_back(5);
    nums.push_back(10);
    nums.push_back(13);
    nums.push_back(15);
    nums.push_back(10);
    nums.push_back(5);
    nums.push_back(16);
    nums.push_back(8);
    Solution solve;
    printf("%d\n", solve.wiggleMaxLength(nums));
    return 0;
}
