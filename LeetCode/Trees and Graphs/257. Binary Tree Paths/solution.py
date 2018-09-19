# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        path, paths = [], []
        self.preorder(root, path, paths)
        return paths

    def preorder(self, node, path: list, paths: list):
        if not node:
            return
        path.append(node.val)
        if not node.left and not node.right:
            path_str = self.path_to_str(path)
            paths.append(path_str)
        self.preorder(node.left, path, paths)
        self.preorder(node.right, path, paths)
        path.pop()

    def path_to_str(self, path):
        path_str = ""
        for val in path:
            path_str += str(val) + "->"
        path_str = path_str[:-2]
        return path_str
