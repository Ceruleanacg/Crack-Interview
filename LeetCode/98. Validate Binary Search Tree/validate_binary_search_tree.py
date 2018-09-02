# https://leetcode.com/problems/validate-binary-search-tree/description/

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """

        ans = []
        self.inOrder(root, ans)

        for i in range(len(ans)-1):
            if ans[i] >= ans[i+1]:
                return False
        return True

    def inOrder(self, root, ans):
        if not root:
            return []

        if root.left:
            self.inOrder(root.left, ans)

        ans.append(root.val)

        if root.right:
            self.inOrder(root.right, ans)


tree = TreeNode(0)
print(Solution().isValidBST(None))
# print(Solution().isValidBST(tree))