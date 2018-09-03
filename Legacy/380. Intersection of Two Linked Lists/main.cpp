//
//  main.cpp
//  380. Intersection of Two Linked Lists
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
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode * getIntersectionNode(ListNode * headA, ListNode * headB) {
        // Declare set.
        std::set<ListNode *> nodes;
        // Insert each node in A.
        while (headA) {
            nodes.insert(headA);
            headA = headA->next;
        }
        while (headB) {
            // Find if exist node in B in A.
            if (nodes.find(headB) != nodes.end()) {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    };
};

int main(int argc, const char * argv[]) {
    
    ListNode a1(1);
    ListNode a2(2);
    ListNode b1(3);
    ListNode b2(4);
    ListNode b3(5);
    ListNode c1(6);
    ListNode c2(7);
    ListNode c3(8);
    a1.next = &a2;
    a2.next = &c1;
    c1.next = &c2;
    c2.next = &c3;
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &c1;
    
    Solution solve;
    ListNode *result = solve.getIntersectionNode(&a1, &b1);
    printf("%d\n", result->val);
    return 0;
}
