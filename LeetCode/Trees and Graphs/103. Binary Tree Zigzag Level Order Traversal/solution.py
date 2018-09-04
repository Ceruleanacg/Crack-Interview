# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """

        if not root:
            return []

        result, level_nodes = [], [root]

        need_inverse = False

        while level_nodes:
            level_result = [node.val for node in level_nodes]
            level_result = level_result if not need_inverse else level_result[::-1]
            need_inverse = ~need_inverse
            result.append(level_result)
            temp_level_nodes = []
            for node in level_nodes:
                if node.left:
                    temp_level_nodes.append(node.left)
                if node.right:
                    temp_level_nodes.append(node.right)
            level_nodes = temp_level_nodes
        return result
