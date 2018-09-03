//
//  main.cpp
//  35. Reverse Linked List
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
     * @param head n
     * @return: The new head of reversed linked list.
     */
    ListNode * reverse(ListNode * head) {
        // Declare the reversed head node.
        ListNode *node_head_reversed = NULL;
        while (head) {
            // Cache next node of head.
            ListNode *node_next_temp = head->next;
            // Update next node of head with reversed head node. (Because current head is tail.)
            head->next = node_head_reversed;
            // Move reversed head node left.
            node_head_reversed = head;
            // Update head with next node.
            head = node_next_temp;
        }
        return node_head_reversed;
    }
};

int main(int argc, const char * argv[]) {
    
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    Solution solve;
    ListNode *head = &a;
    printf("Before reverse:\n");
    while(head){
        printf("%d\n", head->val);
        head = head->next;
    }
    head = solve.reverse(&a);
    printf("After reverse:\n");
    while(head){
        printf("%d\n", head->val);
        head = head->next;
    }
    return 0;
}
