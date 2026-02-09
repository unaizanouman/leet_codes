# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def balanceBST(self,root):

        arr=[]

        def inorder(node):
            if node==None:
                return
            inorder(node.left)
            arr.append(node.val)
            inorder(node.right)

        inorder(root)

        def build(l,r):
            if l>r:
                return None
            mid=(l+r)//2
            node=TreeNode(arr[mid])

            node.left=build(l,mid-1)
            node.right=build(mid+1,r)
            return node
        return build(0,len(arr)-1)    