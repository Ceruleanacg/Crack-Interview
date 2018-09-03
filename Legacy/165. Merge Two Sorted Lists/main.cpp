//
//  main.cpp
//  165. Merge Two Sorted Lists
//
//  Created by Shuyu on 2018/4/1.
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
     * @param l1 ListNode l1 is the head of the linked list
     * @param l2 ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
        // Declare head node.
        ListNode node_head = ListNode(0);
        // Declare ptr of head node.
        ListNode *head_ptr = &node_head;
        // Iteration for inserting node.
        while (l1 && l2) {
            if (l1->val < l2->val) {
                head_ptr->next = l1;
                l1 = l1->next;
            } else {
                head_ptr->next = l2;
                l2 = l2->next;
            }
            head_ptr = head_ptr->next;
        }
        if (l1) {
            head_ptr->next = l1;
        }
        
        if (l2) {
            head_ptr->next = l2;
        }
        
        return node_head.next;
    }
};

int main(int argc, const char * argv[]) {
    ListNode a(1);
    ListNode b(4);
    ListNode c(6);
    ListNode d(0);
    ListNode e(5);
    ListNode f(7);
    a.next = &b;
    b.next = &c;
    d.next = &e;
    e.next = &f;
    Solution solve;
    ListNode *head = solve.mergeTwoLists(&a, &d);
    while(head){
        printf("%d\n", head->val);
        head = head->next;
    }
    return 0;
}
