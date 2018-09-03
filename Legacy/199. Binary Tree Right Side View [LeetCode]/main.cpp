//
//  main.cpp
//  199. Binary Tree Right Side View [LeetCode]
//
//  Created by Shuyu on 2018/4/7.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> views;
        std::queue<std::pair<TreeNode *, int>> queue;
        if (root) {
            queue.push(std::make_pair(root, 0));
        }
        while (!queue.empty()) {
            TreeNode *currentNode = queue.front().first;
            int currentDepth = queue.front().second;
            queue.pop();
            if (views.size() == currentDepth) {
                views.push_back(currentNode->val);
            } else {
                views[currentDepth] = currentNode->val;
            }
            if (currentNode->left) {
                queue.push(std::make_pair(currentNode->left, currentDepth + 1));
            }
            if (currentNode->right) {
                queue.push(std::make_pair(currentNode->right, currentDepth + 1));
            }
        }
        return views;
    }
};

int main(int argc, const char * argv[]) {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(5);
    TreeNode d(3);
    TreeNode e(4);
    TreeNode f(6);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    Solution solve;
    std::vector<int> result = solve.rightSideView(&a);
    for (int i = 0; i < result.size(); i++){
        printf("[%d]\n", result[i]);
    }
    return 0;
}
