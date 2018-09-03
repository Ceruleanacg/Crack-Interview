//
//  main.cpp
//  452. Minimum Number of Arrows to Burst Balloons
//
//  Created by Shuyu on 2018/4/5.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <vector>

bool compare(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    return a.first < b.first;
}

class Solution {
public:
    int findMinArrowShots(std::vector<std::pair<int, int>>& points) {
        if (points.size() == 0) {
            return 0;
        }
        std::sort(points.begin(), points.end(), compare);
        int archer_count = 1;
        int l_shoot_range = points[0].first;
        int r_shoot_range = points[0].second;
        for (int index = 1; index < points.size(); ++index) {
            if (points[index].first <= r_shoot_range) {
                l_shoot_range = points[index].first;
                if (r_shoot_range > points[index].second) {
                    r_shoot_range = points[index].second;
                }
            } else {
                archer_count++;
                l_shoot_range = points[index].first;
                r_shoot_range = points[index].second;
            }
        }
        return archer_count;
    }
};

int main(int argc, const char * argv[]) {
    std::vector<std::pair<int, int> > points;
    points.push_back(std::make_pair(10, 16));
    points.push_back(std::make_pair(2, 8));
    points.push_back(std::make_pair(1, 6));
    points.push_back(std::make_pair(7, 12));
    Solution solve;
    printf("%d\n", solve.findMinArrowShots(points));
    return 0;
}
