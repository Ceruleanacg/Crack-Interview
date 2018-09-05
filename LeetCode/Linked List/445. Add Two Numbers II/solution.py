# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        a, b = 0, 0

        while l1:
            a += a * 10 + l1.val
            l1 = l1.next

        while l2:
            b += b * 10 + l2.val
            l2 = l2.next

        s = a + b

        head_node = ListNode(0)

        while s > 0:
            head_node.val = s % 10
            head_node.next = ListNode(0)
            head_node = head_node.next
