# https://leetcode.com/problems/reverse-linked-list/description/


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        prev = None
        while head:
            cur = head
            head = head.next
            cur.next = prev
            prev = cur
        return prev

    # def reverseList(self, head, prev=None):
    #     """
    #     :type head: ListNode
    #     :rtype: ListNode
    #     """
    #     if not head:
    #         return prev
    #     next = head.next
    #     head.next = prev
    #     return self.reverseList(next, head)


a = ListNode(1)
b = ListNode(2)
c = ListNode(3)
d = ListNode(4)
e = ListNode(5)

a.next = b
b.next = c
c.next = d
d.next = e
e.next = None


p = Solution().reverseList(a)

while p.next:
    print(p.val)
    p = p.next