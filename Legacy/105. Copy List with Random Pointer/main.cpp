//
//  main.cpp
//  105. Copy List with Random Pointer
//
//  Created by Shuyu on 2018/3/31.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    /**
     * @param head The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Declare node map.
        std::map<RandomListNode *, int> node_map;
        // Declare nodes.
        std::vector<RandomListNode *> nodes;
        // Cache head.
        RandomListNode *node_ptr = head;
        // Init nodes and node - index.
        int index = 0;
        while (node_ptr) {
            nodes.push_back(new RandomListNode(node_ptr->label));
            node_map[node_ptr] = index;
            node_ptr = node_ptr->next;
            index++;
        }
        nodes.push_back(0);
        node_ptr = head;
        index = 0;
        // Rebuild random by index.
        while (node_ptr) {
            nodes[index]->next = nodes[index + 1];
            if (node_ptr->random) {
                int _index = node_map[node_ptr->random];
                nodes[index]->random = nodes[_index];
            }
            node_ptr = node_ptr->next;
            index++;
        }
        return nodes[0];
    }
};

int main(int argc, const char * argv[]) {
    RandomListNode a(1);
    RandomListNode b(2);
    RandomListNode c(3);
    RandomListNode d(4);
    RandomListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    a.random = &c;
    b.random = &d;
    c.random = &c;
    e.random = &d;
    Solution solve;
    RandomListNode *head = solve.copyRandomList(&a);
    while(head){
        printf("label = %d ", head->label);
        if (head->random){
            printf("rand = %d\n", head->random->label);
        }
        else{
            printf("rand = NULL\n");
        }
        head = head->next;
    }
    return 0;
}
