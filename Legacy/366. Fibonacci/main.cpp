//
//  main.cpp
//  366. Fibonacci
//
//  Created by Shuyu on 2018/4/12.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <vector>

class Solution {
public:
    /**
     * @param n an integer
     * @return: an ineger f(n)
     */
    int fibonacci(int n) {
        std::vector<int> nums(n, 0);
        nums[0] = 0;
        nums[1] = 1;
        nums[2] = 1;
        for (int i = 3; i < n; ++i) {
            nums[i] = nums[i - 1] + nums[i - 2];
        }
        return nums[n - 1];
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    
    std::cout << s.fibonacci(10) << std::endl;
    std::cout << s.fibonacci(2) << std::endl;
    std::cout << s.fibonacci(1) << std::endl;
    
    return 0;
}
