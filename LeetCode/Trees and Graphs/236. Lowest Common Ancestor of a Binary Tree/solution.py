class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


flag = False


class Solution:

    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        global flag
        p_path, q_path, path = [], [], []
        self.visit(root, p, p_path, path)
        flag, path = False, []
        self.visit(root, q, q_path, path)

        path_length = p_path if len(p_path) < len(q_path) else q_path

        result = None

        for i in range(len(path_length)):
            if p_path[i] == q_path[i]:
                result = p_path[i]
            else:
                break

        return result

    def visit(self, node, target, visit_path: list, path: list):
        global flag
        if not node or flag:
            return
        path.append(node)
        if node == target:
            flag = True
            visit_path = path
        self.visit(node.left, target, visit_path, path)
        self.visit(node.right, target, visit_path, path)
        path.pop()