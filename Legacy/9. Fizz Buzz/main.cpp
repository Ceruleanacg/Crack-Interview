//
//  main.cpp
//  9. Fizz Buzz
//
//  Created by Shuyu on 2018/4/12.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

class Solution {
public:
    /**
     * @param n An integer
     * @return: A list of strings.
     */
    std::vector<std::string> fizzBuzz(int n) {
        std::vector<std::string> results;
        for (int num = 1; num <= n; num++) {
            std::string result;
            if (num % 3 == 0 && num % 5 == 0) {
                result = "fizz buzz";
            }
            else if (num % 3 == 0) {
                result = "fizz";
            }
            else if (num % 5 == 0) {
                result = "buzz";
            }
            else {
                std::stringstream strStream;
                strStream << num;
                result = strStream.str();
            }
            results.push_back(result);
        }
        return results;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution s;
    auto results = s.fizzBuzz(15);
    
    for (auto str : results) {
        std::cout << str << std::endl;
    }
    
    return 0;
}
