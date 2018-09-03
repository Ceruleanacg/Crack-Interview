//
//  main.cpp
//  18. Subsets II
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
     * @param nums A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums) {
        std::vector<std::vector<int>> results;
        std::set<std::vector<int>> resultsSet;
        std::vector<int> subset;
        std::sort(nums.begin(), nums.end());
        results.push_back(subset);
        this->calculateSubsets(0, nums, results, subset, resultsSet);
        return results;
    }
private:
    void calculateSubsets(int index,
                          std::vector<int> &nums,
                          std::vector<std::vector<int>> &results,
                          std::vector<int> &subset,
                          std::set<std::vector<int>> &resultSet) {
        if (index == nums.size()) {
            return;
        }
        
        subset.push_back(nums[index]);
        
        if (resultSet.find(subset) == resultSet.end()) {
            results.push_back(subset);
            resultSet.insert(subset);
        }
        
        this->calculateSubsets(index + 1, nums, results, subset, resultSet);
        
        subset.pop_back();
        
        this->calculateSubsets(index + 1, nums, results, subset, resultSet);
    }
};

int main(int argc, const char * argv[]) {
    std::vector<int> nums;
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    
    std::vector<std::vector<int>> results;
    
    Solution solve;
    
    results = solve.subsetsWithDup(nums);
    
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
