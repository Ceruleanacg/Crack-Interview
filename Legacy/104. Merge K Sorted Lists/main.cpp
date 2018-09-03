//
//  main.cpp
//  104. Merge K Sorted Lists
//
//  Created by Shuyu on 2018/4/1.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

class ListNode {
public:
    int val;
    ListNode *next;
    
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

bool compare(const ListNode *a, const ListNode *b) {
    return a->val < b->val;
}


class Solution {
public:
    /**
     * @param lists a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
        std::vector<ListNode *> nodes;
        for (int index = 0; index < lists.size(); ++index) {
            ListNode *node_ptr = lists[index];
            while (node_ptr) {
                nodes.push_back(node_ptr);
                node_ptr = node_ptr->next;
            }
        }
        if (!nodes.size()) {
            return NULL;
        }
        std::sort(nodes.begin(), nodes.end(), compare);
        for (int index = 0; index < nodes.size() - 1; ++index) {
            nodes[index]->next = nodes[index + 1];
        }
        nodes[nodes.size() - 1]->next = NULL;
        return nodes[0];
    }
};


int main(int argc, const char * argv[]) {
    ListNode a(1);
    ListNode b(4);
    ListNode c(6);
    ListNode d(0);
    ListNode e(5);
    ListNode f(7);
    ListNode g(2);
    ListNode h(3);
    a.next = &b;
    b.next = &c;
    d.next = &e;
    e.next = &f;
    g.next = &h;
    Solution solve;
    std::vector<ListNode *> lists;
    lists.push_back(&a);
    lists.push_back(&d);
    lists.push_back(&g);
    ListNode *head = solve.mergeKLists(lists);
    while(head){
        printf("%d\n", head->val);
        head = head->next;
    }
}
