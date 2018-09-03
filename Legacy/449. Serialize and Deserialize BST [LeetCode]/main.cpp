//
//  main.cpp
//  449. Serialize and Deserialize BST [LeetCode]
//
//  Created by Shuyu on 2018/4/10.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Codec {
public:
    
    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        std::string data;
        this->preorderTraverse(root, data);
        return data;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        if (!data.length()) {
            return NULL;
        }
        std::vector<TreeNode *> nodes;
        int val = 0;
        for (int i = 0; i < data.length(); ++i) {
            if (data[i] != '#') {
                val = val * 10 + data[i] - '0';
            }
            else {
                nodes.push_back(new TreeNode(val));
                val = 0;
            }
        }
        for (int i = 1; i < nodes.size(); ++i) {
            this->insertNode(nodes[0], nodes[i]);
        }
        return nodes[0];
    }
    
    void preorderTraverse(TreeNode *node, std::string &data) {
        if (!node) {
            return;
        }
        std::string str;
        this->convertIntToString(node->val, str);
        data += str;
        this->preorderTraverse(node->left, data);
        this->preorderTraverse(node->right, data);
    }
    
private:
    void convertIntToString(int val, std::string &str) {
        std::string result;
        while (val) {
            result += val % 10 + '0';
            val /= 10;
        }
        for (int i = (int)result.length() - 1; i >= 0; i--) {
            str += result[i];
        }
        str += '#';
    }
    void insertNode(TreeNode *node, TreeNode *targetNode) {
        if (targetNode->val < node->val) {
            if (node->left) {
                this->insertNode(node->left, targetNode);
            }
            else {
                node->left = targetNode;
            }
        }
        else {
            if (node->right) {
                this->insertNode(node->right, targetNode);
            }
            else {
                node->right = targetNode;
            }
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main(int argc, const char * argv[]) {
    TreeNode a(8);
    TreeNode b(3);
    TreeNode c(10);
    TreeNode d(1);
    TreeNode e(6);
    TreeNode f(15);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    Codec solve;
    std::string data = solve.serialize(&a);
    printf("%s\n", data.c_str());
    TreeNode *root = solve.deserialize(data);
    solve.preorderTraverse(root, data);
    return 0;
}
