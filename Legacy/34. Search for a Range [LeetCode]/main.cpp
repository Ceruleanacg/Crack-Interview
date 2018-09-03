//
//  main.cpp
//  34. Search for a Range [LeetCode]
//
//  Created by Shuyu on 2018/4/10.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        std::vector<int> result;
        result.push_back(this->findLeftBound(nums, target));
        result.push_back(this->findRightBound(nums, target));
        return result;
        
    }
private:
    int findLeftBound(std::vector<int> &nums, int target) {
        int begin = 0;
        int end = (int)nums.size() - 1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (target == nums[mid]) {
                if (mid == 0) {
                    return mid;
                }
                if (nums[mid - 1] < target) {
                    return mid;
                }
                end = mid - 1;
            }
            else if (target < nums[mid]) {
                end = mid - 1;
            }
            else if (target > nums[mid]) {
                begin = mid + 1;
            }
        }
        return -1;
    }
    
    int findRightBound(std::vector<int> &nums, int target) {
        int begin = 0;
        int end = (int)nums.size() - 1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (target == nums[mid]) {
                if (mid == nums.size() - 1) {
                    return mid;
                }
                if (nums[mid + 1] > target) {
                    return mid;
                }
                begin = mid + 1;
            }
            else if (target < nums[mid]) {
                end = mid - 1;
            }
            else if (target > nums[mid]) {
                begin = mid + 1;
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    int test[] = {5, 7, 7, 8, 8, 8, 8, 10};
    std::vector<int> nums;
    Solution solve;
    for (int i = 0; i < 8; i++){
        nums.push_back(test[i]);
    }
    for (int i = 0; i < 12; i++){
        std::vector<int> result = solve.searchRange(nums, i);
        printf("%d : [%d, %d]\n",i , result[0], result[1]);
    }
    return 0;
}
