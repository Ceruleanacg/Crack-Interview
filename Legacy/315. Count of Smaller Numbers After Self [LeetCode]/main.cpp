//
//  main.cpp
//  249. Count of Smaller Number before itself
//
//  Created by Shuyu on 2018/4/6.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <vector>

class Solution {
public:
    /**
     * @param nums an integer array
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    std::vector<int> countSmaller(std::vector<int> &nums) {
        std::vector<std::pair<int, int>> pairVec;
        std::vector<int> results;
        for (auto i = 0; i < nums.size(); ++i) {
            pairVec.push_back(std::make_pair(nums[i], i));
            results.push_back(0);
        }
        mergeSort(pairVec, results);
        return results;
    }
    
private:
    
    void mergeSort(std::vector<std::pair<int, int>> &vec, std::vector<int> &results) {
        if (vec.size() < 2) {
            return;
        }
        int mid = (int)(vec.size() / 2);
        std::vector<std::pair<int, int>> a;
        std::vector<std::pair<int, int>> b;
        for (auto i = 0; i < mid; ++i) {
            a.push_back(vec[i]);
        }
        for (auto i = mid; i < vec.size(); ++i) {
            b.push_back(vec[i]);
        }
        this->mergeSort(a, results);
        this->mergeSort(b, results);
        vec.clear();
        this->mergeTwoVector(a, b, vec, results);
    }
    
    void mergeTwoVector(std::vector<std::pair<int, int>> &a,
                        std::vector<std::pair<int, int>> &b,
                        std::vector<std::pair<int, int>> &vec,
                        std::vector<int> &result) {
        int i = 0;
        int j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i].first <= b[j].first) {
                result[a[i].second] += j;
                vec.push_back(a[i]);
                ++i;
            } else {
                vec.push_back(b[j]);
                ++j;
            }
        }
        for (; i < a.size(); ++i) {
            result[a[i].second] += j;
            vec.push_back(a[i]);
        }
        for (; j < b.size(); ++j) {
            vec.push_back(b[j]);
        }
    }
};


int main(int argc, const char * argv[]) {
    
    //    int test[] = {5, -7, 9, 1, 3, 5, -2, 1};
    
    int test[] = {5, 2, 6, 1};
    
    std::vector<int> nums;
    
    for (auto i = 0; i < 4; ++i) {
        nums.push_back(test[i]);
    }
    
    Solution s;
    
    auto result = s.countSmaller(nums);
    
    for (auto num : result) {
        std::cout << "[" << num << "]";
    }
    
    std::cout << std::endl;
    
    return 0;
}
