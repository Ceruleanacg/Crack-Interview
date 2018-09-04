# https://leetcode.com/problems/add-two-numbers/description/


class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0

        head_node = ListNode(0)
        cur_node = head_node

        while l1 and l2:
            cur_sum = l1.val + l2.val + carry
            carry = 0 if cur_sum < 10 else 1
            cur_sum = cur_sum % 10

            cur_node.val = cur_sum

            l1 = l1.next
            l2 = l2.next

            if l1 and l2:
                cur_node.next = ListNode(0)
                cur_node = cur_node.next

        l_last = l1 if l1 else l2

        while l_last:
            cur_sum = l_last.val + carry
            carry = 0 if cur_sum < 10 else 1
            cur_sum = cur_sum % 10

            cur_node.next = ListNode(cur_sum)
            cur_node = cur_node.next

            l_last = l_last.next

        if carry:
            cur_node.next = ListNode(1)

        return head_node

