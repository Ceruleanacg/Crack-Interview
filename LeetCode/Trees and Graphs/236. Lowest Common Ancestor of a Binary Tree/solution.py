class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:

    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        flag = False
        p_path, q_path, path = [], [], []
        self.visit(root, p, p_path, path, flag)
        flag, path = False, []
        self.visit(root, q, q_path, path, flag)

        short_path_length = p_path if len(p_path) < len(q_path) else q_path

        result = None

        for i in range(len(short_path_length)):
            if p_path[i] == q_path[i]:
                result = p_path[i]
            else:
                break

        return result

    def visit(self, node, target, visit_path, path, flag):
        if not node or flag:
            return
        path.append(node)
        if node.val == target.val:
            flag = True
            visit_path.extend(path)
        self.visit(node.left, target, visit_path, path, flag)
        self.visit(node.right, target, visit_path, path, flag)
        path.pop()


root = TreeNode(3)
root.left = TreeNode(5)
root.right = TreeNode(1)
root.left.left = TreeNode(6)
root.left.right = TreeNode(2)
root.left.right.left = TreeNode(7)
root.left.right.left = TreeNode(4)
root.right.left = TreeNode(0)
root.right.right = TreeNode(8)

print(Solution().lowestCommonAncestor(root, TreeNode(5), TreeNode(4)).val)
