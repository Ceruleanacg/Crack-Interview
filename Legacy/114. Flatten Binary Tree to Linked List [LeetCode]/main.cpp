//
//  main.cpp
//  114. Flatten Binary Tree to Linked List [LeetCode]
//
//  Created by Shuyu on 2018/4/7.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *lastNode = NULL;
        preorderTraverse(root, lastNode);
    }
private:
    void preorderTraverse(TreeNode *node, TreeNode *&lastNode) {
        if (!node) {
            return;
        }
        if (!node->left && !node->right) {
            lastNode = node;
            return;
        }
        TreeNode *lNode = node->left;
        TreeNode *rNode = node->right;
        TreeNode *lLastNode = NULL;
        TreeNode *rLastNode = NULL;
        if (lNode) {
            preorderTraverse(lNode, lLastNode);
            node->left = NULL;
            node->right = lNode;
            lastNode = lLastNode;
        }
        if (rNode) {
            preorderTraverse(rNode, rLastNode);
            if (lLastNode) {
                lLastNode->right = rNode;
            }
            lastNode = rLastNode;
        }
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
    solve.flatten(&a);
    TreeNode *head = &a;
    while(head){
        if (head->left){
            printf("ERROR\n");
        }
        printf("[%d]", head->val);
        head = head->right;
    }
    printf("\n");
    return 0;
}
