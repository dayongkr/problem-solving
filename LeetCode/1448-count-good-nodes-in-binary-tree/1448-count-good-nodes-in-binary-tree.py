# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, x: int, root: TreeNode) -> int:
        if not root:
            return 0

        x = max(x, root.val)
        count = self.dfs(x, root.left) + self.dfs(x, root.right)

        if root.val >= x:
            count += 1
        
        return count


    def goodNodes(self, root: TreeNode) -> int:
        return self.dfs(root.val, root)