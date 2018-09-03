//
//  main.cpp
//  103. Linked List Cycle II
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
    /*
     * @param head: The first node of linked list.
     * @return: The node where the cycle begins. if there is no cycle, return null
     */
    ListNode * detectCycle(ListNode * head) {
        // Declare slow, fast, meet ptr.
        ListNode *slow_ptr = head;
        ListNode *fast_ptr = head;
        ListNode *meet_ptr = NULL;
        // Detect cycle.
        while (fast_ptr) {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next;
            if (!fast_ptr) {
                break;
            }
            fast_ptr = fast_ptr->next;
            if (fast_ptr == slow_ptr) {
                meet_ptr = fast_ptr;
                break;
            }
        }
        // If there is no cycle.
        if (!meet_ptr) {
            return NULL;
        }
        // Exists cycle.
        while (head && meet_ptr) {
            // IMPORTANT THEORY: if cycle exists, the intersection of head and meet is where the cycle start.
            if (head == meet_ptr) {
                return meet_ptr;
            }
            head = head->next;
            meet_ptr = meet_ptr->next;
        }
        
        return meet_ptr;
    }
};

int main(int argc, const char * argv[]) {
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    ListNode f(6);
    ListNode g(7);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    g.next = &c;
    Solution solve;
    ListNode *node = solve.detectCycle(&a);
    if (node){
        printf("%d\n", node->val);
    }
    else{
        printf("NULL\n");
    }
    return 0;
    
    return 0;
}
