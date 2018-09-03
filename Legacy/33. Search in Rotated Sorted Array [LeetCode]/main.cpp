//
//  main.cpp
//  33. Search in Rotated Sorted Array [LeetCode]
//
//  Created by Shuyu on 2018/4/10.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int begin = 0;
        int end = (int)nums.size() - 1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (target == nums[mid]) {
                return mid;
            }
            else if (target < nums[mid]) {
                // If current range is incrasing.
                if (nums[begin] < nums[mid]) {
                    if (target >= nums[begin]) {
                        // Normal binary search.
                        end = mid - 1;
                    }
                    else {
                        // Target is less than num[begin], search in rotated range.
                        begin = mid + 1;
                    }
                }
                else if (nums[begin] > nums[mid]) {
                    // num[mid] is in rotated range, modify end.
                    end = mid - 1;
                }
                else if (nums[begin] == nums[mid]) {
                    // Target is less than nums[mid], but nums[begin] == nums[mid], search in rotated range.
                    begin = mid + 1;
                }
            }
            else if (target > nums[mid]) {
                // If current range is incrasing.
                if (nums[begin] < nums[mid]) {
                    begin = mid + 1;
                }
                else if (nums[begin] > nums[mid]) {
                    if (target >= nums[begin]) {
                        end = mid - 1;
                    }
                    else {
                        begin = mid + 1;
                    }
                }
                else if (nums[begin] == nums[mid]) {
                    begin = mid + 1;
                }
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    int test[] = {9, 12, 15, 20, 1, 3, 6, 7};
    std::vector<int> nums;
    Solution solve;
    for (int i = 0; i < 8; i++){
        nums.push_back(test[i]);
    }
    for (int i = 0; i < 22; i++){
        printf("%d : %d\n", i, solve.search(nums, i));
    }
    return 0;
}
