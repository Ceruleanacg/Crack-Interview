# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def mergeKLists(self, lists: list):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        if len(lists) == 0:
            return None

        if len(lists) == 1:
            return lists[0]

        node_result = self.merge_two_sorted_lists(lists.pop(), lists.pop())

        while lists:
            node_result = self.merge_two_sorted_lists(node_result, lists.pop())

        return node_result

    def merge_two_sorted_lists(self, node_a, node_b):
        head_node = ListNode(-1)
        cur_node = head_node
        while node_a and node_b:
            if node_a.val < node_b.val:
                cur_node.next = node_a
                node_a = node_a.next
            else:
                cur_node.next = node_b
                node_b = node_b.next
            cur_node = cur_node.next
        cur_node.next = node_a or node_b
        return head_node.next
