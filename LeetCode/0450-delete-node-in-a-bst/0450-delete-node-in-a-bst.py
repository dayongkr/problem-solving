# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if not root:
            return
        
        if root.val > key:
            self.deleteNode(root.left, key)
        elif root.val < key:
            self.deleteNode(root.right, key)
        else:
            if root.right:
                rightChild = self.deleteNode(root.right, root.right.val)
                root.val = rightChild.val

                if not rightChild.left and not rightChild.right:
                    root.right = None
            elif root.left:
                leftChild = self.deleteNode(root.left, root.left.val)
                root.val = left.val

                if not leftChild.left and not leftChild.right:
                    root.left = None

        return root