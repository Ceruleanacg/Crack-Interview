//
//  main.cpp
//  Immortals
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
     * @param head ListNode head is the head of the linked list
     * @param m An integer
     * @param n An integer
     * @return: The head of the reversed ListNode
     */
    ListNode * reverseBetween(ListNode * head, int m, int n){
        // Calculate change length.
        int change_length = n - m + 1;
        // Declare reversed head.
        ListNode *head_result = head;
        // Find node where we start reverse.
        ListNode *node_reversal_head_hook = NULL;
        while (head && --m) {
            node_reversal_head_hook = head;
            head = head->next;
        }
        // Cache reversal tail.
        ListNode *node_reversal_tail = head;
        // Declare head for reversal part.
        ListNode *head_reversed = NULL;
        // Start reverse.
        while (head && change_length) {
            // Cache next node.
            ListNode *node_next = head->next;
            // Update next node of head with reversed head node. (Because current head is tail.)
            head->next = head_reversed;
            // Move reversed head node left.
            head_reversed = head;
            // Update node start.
            head = node_next;
            // Decrase change length.
            change_length--;
        }
        // Link tail with real head.
        node_reversal_tail->next = head;
        // Link head with tail if need.
        if (node_reversal_head_hook) {
            node_reversal_head_hook->next = head_reversed;
        } else {
            head_result = head_reversed;
        }
        return head_result;
    };
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
    head = solve.reverseBetween(&a, 2, 4);
    printf("After reverse:\n");
    while(head){
        printf("%d\n", head->val);
        head = head->next;
    }
    return 0;
}
