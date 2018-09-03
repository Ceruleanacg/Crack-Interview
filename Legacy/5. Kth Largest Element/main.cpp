//
//  main.cpp
//  5. Kth Largest Element
//
//  Created by Shuyu on 2018/4/3.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    /*
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, std::vector<int> &nums) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
        for (int index = 0; index < nums.size(); ++index) {
            if (min_heap.size() < n) {
                min_heap.push(nums[index]);
            } else {
                if (min_heap.top() < nums[index]) {
                    min_heap.pop();
                    min_heap.push(nums[index]);
                }
            }
        }
        return min_heap.top();
    }
};

int main(int argc, const char * argv[]) {
    std::vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(4);
    Solution solve;
    printf("%d\n", solve.kthLargestElement(2, nums));
    return 0;
}
