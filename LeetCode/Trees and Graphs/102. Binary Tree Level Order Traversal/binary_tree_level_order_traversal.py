# https://leetcode.com/problems/binary-tree-level-order-traversal/description/


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        result, level = [], [root]
        while level:
            result.append([node.val for node in level])
            level_temp = []
            for node in level:
                level_temp.extend([node.left, node.right])
            level = []
            for node in level_temp:
                if node:
                    level.append(node)
        return result

    def _levelOrder(self, root):

        if not root:
            return []

        result, cur_level_nodes = [], [root]

        while cur_level_nodes:
            # Add vals for current level.
            cur_node_vals = [node.val for node in cur_level_nodes]
            result.append(cur_node_vals)
            # Update level nodes.
            next_level_nodes = []
            for node in cur_level_nodes:
                if node.left:
                    next_level_nodes.append(node.left)
                if node.right:
                    next_level_nodes.append(node.right)
            cur_level_nodes = next_level_nodes
        return result





