//
//  main.cpp
//  102. Linked List Cycle
//
//  Created by Shuyu on 2018/3/31.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <set>

class ListNode {
public:
    int val;
    ListNode *next;
    
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Solution {
public:
    /*
     * @param head: The first node of linked list.
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode * head) {
        std::set<ListNode *> nodes;
        while (head) {
            if (nodes.find(head) != nodes.end()) {
                return true;
            }
            nodes.insert(head);
            head = head->next;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    ListNode f(6);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &c;
    Solution solve;
    if (solve.hasCycle(&a)){
        printf("True");
    }
    else{
        printf("NULL\n");
    }
    return 0;
}
