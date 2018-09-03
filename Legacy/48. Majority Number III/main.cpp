//
//  main.cpp
//  48. Majority Number III
//
//  Created by Shuyu on 2018/4/12.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    /**
     * @param nums A list of integers
     * @param k An integer
     * @return: The majority number
     */
    int majorityNumber(std::vector<int> &nums, int k) {
        float targetPercent = (float)k / nums.size();
        std::map<int, int> numMap;
        for (auto i = 0; i < nums.size(); ++i) {
            if (numMap.find(nums[i]) != numMap.end()) {
                numMap[nums[i]]++;
            } else {
                numMap[nums[i]] = 1;
            }
        }
        int reuslt = nums[0];
        for (auto pair : numMap) {
            float currentPercent = (float)pair.second / nums.size();
            if (currentPercent > targetPercent) {
                reuslt = pair.first;
            }
        }
        return reuslt;
    }
};

int main(int argc, const char * argv[]) {
    
    std::vector<int> nums;
//    nums.push_back(3);
//    nums.push_back(1);
//    nums.push_back(2);
//    nums.push_back(3);
//    nums.push_back(2);
//    nums.push_back(3);
//    nums.push_back(3);
//    nums.push_back(4);
//    nums.push_back(4);
//    nums.push_back(4);
    
    nums.push_back(7);
    nums.push_back(1);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(61);
    nums.push_back(61);
    nums.push_back(61);
    nums.push_back(10);
    nums.push_back(10);
    nums.push_back(10);
    nums.push_back(61);
    
//    nums.push_back(1);
//    nums.push_back(1);
//    nums.push_back(2);
    
    Solution s;
    std::cout << s.majorityNumber(nums, 3) << std::endl;
    
    return 0;
}
