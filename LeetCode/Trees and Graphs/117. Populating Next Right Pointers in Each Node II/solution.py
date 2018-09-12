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
            nodes = []
            for node in level_nodes:
                if node.left:
                    nodes.append(node.left)
                if node.right:
                    nodes.append(node.right)
                for index in range(len(nodes) - 1):
                    nodes[index].next = nodes[index + 1]
                if nodes:
                    nodes[-1].next = None
            level_nodes = nodes

