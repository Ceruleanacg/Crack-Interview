# https://leetcode.com/problems/linked-list-cycle/description/

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """

        if not head:
            return False

        slow_node = head
        fast_node = head.next

        while True and slow_node and fast_node:
            if slow_node == fast_node:
                return True

            slow_node = slow_node.next

            fast_node = fast_node.next

            if fast_node:
                fast_node = fast_node.next

        return False