//
//  main.cpp
//  113. Path Sum II [LeetCode]
//
//  Created by Shuyu on 2018/4/7.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<std::vector<int>> pathSum(TreeNode* root, int sum) {
        std::vector<std::vector<int>> results;
        std::vector<int> values;
        int currentValue = 0;
        this->preorderTraverse(root, values, currentValue, results, sum);
        return results;
    }
private:
    void preorderTraverse(TreeNode *node,
                          std::vector<int> &values,
                          int &currentValue,
                          std::vector<std::vector<int>> &results,
                          int sum) {
        if (!node) {
            return;
        }
        
        currentValue += node->val;
        values.push_back(node->val);
        
        
        if (currentValue == sum && !node->left && !node->right) {
            results.push_back(values);
        }
        
        this->preorderTraverse(node->left, values, currentValue, results, sum);
        this->preorderTraverse(node->right, values, currentValue, results, sum);
        
        currentValue -= node->val;
        
        values.pop_back();
    }
};

int main(int argc, const char * argv[]) {
    TreeNode a(5);
    TreeNode b(4);
    TreeNode c(8);
    TreeNode d(11);
    TreeNode e(13);
    TreeNode f(4);
    TreeNode g(7);
    TreeNode h(2);
    TreeNode x(5);
    TreeNode y(1);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    c.left = &e;
    c.right = &f;
    d.left = &g;
    d.right = &h;
    f.left = &x;
    f.right = &y;
    Solution solve;
    std::vector<std::vector<int> > result = solve.pathSum(&a, 22);
    for (int i = 0; i < result.size(); i++){
        for (int j = 0; j < result[i].size(); j++){
            printf("[%d]", result[i][j]);
        }
        printf("\n");
    }
}
