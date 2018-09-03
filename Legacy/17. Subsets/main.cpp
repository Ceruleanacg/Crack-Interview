//
//  main.cpp
//  17. Subsets
//
//  Created by Shuyu on 2018/4/6.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    /**
     * @param nums A set of numbers
     * @return: A list of lists
     */
    std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
        // Declare results for all subset.
        std::vector<std::vector<int>> results;
        // Declare current subset.
        std::vector<int> subset;
        // Add non-set to subset.
        results.push_back(subset);
        // Recursive calculate subsets.
        this->calculateSubsets(0, nums, subset, results);
        // Sort result.
        for (int index = 0; index < results.size(); ++index) {
            std::sort(results[index].begin(), results[index].end());
        }
        // Return results.
        return results;
    };
private:
    void calculateSubsets(int index,
                          std::vector<int> &nums,
                          std::vector<int> &subset,
                          std::vector<std::vector<int>> &results) {
        
        if (index == nums.size()) {
            return;
        }
        
        subset.push_back(nums[index]);
        results.push_back(subset);
        this->calculateSubsets(index + 1, nums, subset, results);
        subset.pop_back();
        this->calculateSubsets(index + 1, nums, subset, results);
        
    };
};

class SolutionB {
public:
    std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
        std::vector<std::vector<int>> results;
        
        int setBits = 1 << nums.size();
        
        for (int index = 0; index < setBits; ++index) {
            std::vector<int> subset;
            for (int j = 0; j < nums.size(); ++j) {
                if (index & (1 << j)) {
                    subset.push_back(nums[j]);
                }
            }
            results.push_back(subset);
        }
        
        return results;
    };
};

int main(int argc, const char * argv[]) {
    
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    
    std::vector<std::vector<int>> results;
    
//    Solution solve;
    SolutionB solve;
    
    results = solve.subsets(nums);
    
    for (int index = 0; index < results.size(); ++index) {
        if (results[index].size() == 0) {
            std::cout << "[]";
        }
        for (int i_index = 0; i_index < results[index].size(); ++i_index) {
            std::cout << "[" << results[index][i_index] << "]";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
