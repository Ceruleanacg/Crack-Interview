# https://leetcode.com/problems/add-two-numbers/description/

# Definition for singly-linked list.
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
        # l1_reversed = self.reverse_linked_list(l1)
        # l2_reversed = self.reverse_linked_list(l2)

        head_node = None

        cur_node = None

        carry = 0

        while l1 and l2:
            # 1. Calculate current sum.
            cur_val = l1.val + l2.val + carry
            # 2. Check if sum over 9.
            if cur_val > 9:
                cur_val = cur_val % 10
                carry = 1
            else:
                carry = 0
            # 3. Append result.
            if not head_node:
                head_node = ListNode(cur_val)
                cur_node = head_node
            else:
                cur_node.next = ListNode(cur_val)
                cur_node = cur_node.next
            l1 = l1.next
            l2 = l2.next

        self.add_last(l1, cur_node, carry)
        self.add_last(l2, cur_node, carry)

        if carry:
            head_node.next = ListNode(carry)

        return head_node

    def add_last(self, l, cur_node, carry):
        if not l:
            return
        while l:
            cur_sum = l.val + carry
            if cur_sum > 9:
                cur_sum = cur_sum % 10
                carry = 1
            else:
                carry = 0
            cur_node.next = ListNode(cur_sum)
            l = l.next
        if carry:
            cur_node.next = ListNode(carry)
        return


    def reverse_linked_list(self, head):

        if not head:
            return head

        pre_node = None

        while head:
            # 1. Get current node.
            cur_node = head
            # 2. Update next node of current node.
            cur_node.next = pre_node
            # 3. Update previous node.
            pre_node = cur_node
            # 4. Update head node.
            head = head.next

        return pre_node
