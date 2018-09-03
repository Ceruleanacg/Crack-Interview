//
//  main.cpp
//  153. Combination Sum II
//
//  Created by Shuyu on 2018/4/6.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

class Solution {
public:
    /**
     * @param nums Given the candidate numbers
     * @param target Given the target number
     * @return: All the combinations that sum to target
     */
    std::vector<std::vector<int>> combinationSum2(std::vector<int> &nums, int target) {
        std::vector<std::vector<int>> results;
        std::vector<int> subset;
        std::set<std::vector<int>> resultsChecker;
        std::sort(nums.begin(), nums.end());
        this->calculateSubset(0, nums, results, subset, resultsChecker, 0, target);
        return results;
    }
private:
    void calculateSubset(int index,
                         std::vector<int> &nums,
                         std::vector<std::vector<int>> &results,
                         std::vector<int> &subset,
                         std::set<std::vector<int>> &resultsChecker,
                         int sum,
                         int target) {
        
        if (index == nums.size() || sum > target) {
            return;
        }
        
        subset.push_back(nums[index]);
        
        sum += nums[index];
        
        if (sum == target && resultsChecker.find(subset) == resultsChecker.end()) {
            results.push_back(subset);
            resultsChecker.insert(subset);
        }
        
        this->calculateSubset(index + 1, nums, results, subset, resultsChecker, sum, target);
        
        sum -= nums[index];
        
        subset.pop_back();
        
        this->calculateSubset(index + 1, nums, results, subset, resultsChecker, sum, target);
    }
};

int main(int argc, const char * argv[]) {
    std::vector<int> nums;
    nums.push_back(10);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(6);
    nums.push_back(1);
    nums.push_back(5);
    
    std::vector<std::vector<int>> results;
    
    Solution solve;
    
    results = solve.combinationSum2(nums, 8);
    
    for (int index = 0; index < results.size(); ++index) {
        if (results[index].size() == 0) {
            std::cout << "[]";
        }
        for (int i_index = 0; i_index < results[index].size(); ++i_index) {
            std::cout << "[" << results[index][i_index] << "]";
        }
        std::cout << std::endl;
    }
}
