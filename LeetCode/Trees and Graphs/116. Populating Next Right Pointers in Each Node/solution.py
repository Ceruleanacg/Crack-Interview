# Definition for binary tree with next pointer.
class TreeLinkNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        self.next = None


class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        if not root:
            return

        level_nodes = [root]

        while level_nodes:
            next_level_nodes = []
            for node in level_nodes:
                if node.left and node.right:
                    next_level_nodes.append(node.left)
                    next_level_nodes.append(node.right)
            for index, node in enumerate(next_level_nodes[:-1]):
                node.next = next_level_nodes[index + 1]
            level_nodes = next_level_nodes
