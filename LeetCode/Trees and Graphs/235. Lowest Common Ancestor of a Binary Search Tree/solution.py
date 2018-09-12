# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        pval, qval = min(p.val, q.val), max(q.val, p.val)
        if pval < qval < root.val:
            return self.lowestCommonAncestor(root.left, p, q)
        elif root.val < pval < qval:
            return self.lowestCommonAncestor(root.right, p, q)
        return root
