from collections import deque

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        queue = deque()

        if root:
            queue.append((root, 1))

            while queue:
                top, depth = queue.popleft()

                if not queue or queue[0][1] > depth:
                    result.append(top.val)
                
                if top.left:
                    queue.append((top.left, depth + 1))

                if top.right:
                    queue.append((top.right, depth + 1))

        return result