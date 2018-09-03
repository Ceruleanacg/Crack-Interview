//
//  main.cpp
//  96. Partition List
//
//  Created by Shuyu on 2018/3/31.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>

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
    /**
     * @param head The first node of linked list
     * @param x An integer
     * @return: A ListNode
     */
    ListNode * partition(ListNode * head, int x) {
        ListNode less_node = ListNode(0);
        ListNode more_node = ListNode(0);
        ListNode *less_node_ptr = &less_node;
        ListNode *more_node_ptr = &more_node;
        while (head) {
            if (head->val < x) {
                less_node_ptr->next = head;
                less_node_ptr = less_node_ptr->next;
            } else {
                more_node_ptr->next = head;
                more_node_ptr = more_node_ptr->next;
            }
            head = head->next;
        }
        less_node_ptr->next = more_node.next;
        more_node_ptr->next = NULL;
        return less_node.next;
    }
};

int main(int argc, const char * argv[]) {
    ListNode a(1);
    ListNode b(4);
    ListNode c(3);
    ListNode d(2);
    ListNode e(5);
    ListNode f(2);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    Solution solve;
    ListNode *head = solve.partition(&a, 3);
    while(head){
        printf("%d\n", head->val);
        head = head->next;
    }
    return 0;
}
