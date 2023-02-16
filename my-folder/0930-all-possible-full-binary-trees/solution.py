# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:
        if n % 2 == 0:
            return []
        def FBT(m):
            if m == 1:
                return [TreeNode(0)]
            res = []
            for i in range(1, m - 1):
                for left in FBT(i):
                    for right in FBT(m - 1 - i):
                        root = TreeNode(0, left, right)
                        res.append(root)
            return res
        return FBT(n)
