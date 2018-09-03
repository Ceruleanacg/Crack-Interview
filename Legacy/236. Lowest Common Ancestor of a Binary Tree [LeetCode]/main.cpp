//
//  main.cpp
//  236. Lowest Common Ancestor of a Binary Tree [LeetCode]
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        std::vector<TreeNode *> path;
        std::vector<TreeNode *> firstPath;
        std::vector<TreeNode *> secondPath;
        
        bool finishFlag = false;
        
        preorderTraverse(root, p, path, firstPath, finishFlag);
        
        path.clear();
        
        finishFlag = false;
        
        preorderTraverse(root, q, path, secondPath, finishFlag);
        
        TreeNode *result = NULL;
        
        unsigned long pathLength = firstPath.size() > secondPath.size() ? secondPath.size() : firstPath.size();
        
        for (int index = 0; index < pathLength; ++index) {
            if (firstPath[index] == secondPath[index]) {
                result = firstPath[index];
            } else {
                break;
            }
        }
        
        return result;
    }
private:
    void preorderTraverse(TreeNode *node,
                          TreeNode *target,
                          std::vector<TreeNode *> &path,
                          std::vector<TreeNode *> &result,
                          bool &finishFlag) {
        if (!node || finishFlag){
            return;
        }
        path.push_back(node);
        if (node == target){
            finishFlag = 1;
            result = path;
        }
        preorderTraverse(node->left, target, path, result, finishFlag);
        preorderTraverse(node->right, target, path, result, finishFlag);
        path.pop_back();
    }
};

int main(int argc, const char * argv[]) {
    TreeNode a(3);
    TreeNode b(5);
    TreeNode c(1);
    TreeNode d(6);
    TreeNode e(2);
    TreeNode f(0);
    TreeNode x(8);
    TreeNode y(7);
    TreeNode z(4);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &x;
    e.left = &y;
    e.right = &z;
    
    Solution solve;
    TreeNode *result = solve.lowestCommonAncestor(&a, &b, &f);
    printf("lowestCommonAncestor = %d\n", result->val);
    result = solve.lowestCommonAncestor(&a, &d, &z);
    printf("lowestCommonAncestor = %d\n", result->val);
    result = solve.lowestCommonAncestor(&a, &b, &y);
    printf("lowestCommonAncestor = %d\n", result->val);
    
    return 0;
}
