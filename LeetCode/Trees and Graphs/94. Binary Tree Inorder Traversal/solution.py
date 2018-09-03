# https://leetcode.com/problems/binary-tree-inorder-traversal/description/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        result = []
        stack = [(root, False)]

        while stack:
            current_node, visited = stack.pop()
            if current_node:
                if visited:
                    result.append(current_node.val)
                else:
                    stack.append((current_node.right, False))
                    stack.append((current_node, True))
                    stack.append((current_node.left, False))

        return result

    def in_order(self, root, result):

        if not root:
            return

        if root.left:
            self.in_order(root.left, result)

        result.append(root.val)

        if root.right:
            self.in_order(root.right, result)


