//
//  main.cpp
//  81. Data Stream Median
//
//  Created by Shuyu on 2018/4/3.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    /**
     * @param nums A list of integers
     * @return: the median of numbers
     */
    std::vector<int> medianII(std::vector<int> &nums) {
        std::vector<int> indices;
        for (int index = 0; index < nums.size(); ++index) {
            this->addNumber(nums[index]);
            indices.push_back(this->calculateMedian());
        }
        return indices;
    }
    
    double calculateMedian() {
        if (max_heap.size() == min_heap.size()) {
            return max_heap.top();
        } else if (max_heap.size() > min_heap.size()) {
            return max_heap.top();
        } else {
            return min_heap.top();
        }
    }
    
    void addNumber(int num) {
        if (max_heap.empty()) {
            max_heap.push(num);
            return;
        }
        if (max_heap.size() == min_heap.size()) {
            if (num < max_heap.top()) {
                max_heap.push(num);
            } else {
                min_heap.push(num);
            }
        } else if (max_heap.size() > min_heap.size()) {
            if (num > max_heap.top()) {
                min_heap.push(num);
            } else {
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            }
        } else {
            if (num < min_heap.top()) {
                max_heap.push(num);
            } else {
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(num);
            }
        }
    }
    
private:
    std::priority_queue<int> max_heap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
};

int main(int argc, const char * argv[]) {
    Solution s;
//    int test[] = {6, 10, 1, 7, 99, 4, 33};
//    int test[] = {1, 2, 3, 4, 5};
    int test[] = {4, 5, 1, 3, 2, 6, 0};
    std::vector<int> v(test, test + 7);
    std::vector<int> result = s.medianII(v);
    return 0;
}
