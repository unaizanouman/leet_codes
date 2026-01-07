# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxProduct(self, root):
        MOD = 10**9 + 7
        
        # First pass: compute total sum
        total_sum = [0]
        def compute_total(node):
            if not node:
                return 0
            total = node.val + compute_total(node.left) + compute_total(node.right)
            total_sum[0] = total
            return total
        
        compute_total(root)
        total = total_sum[0]
        
        # Second pass: find maximum product
        max_product = [0]
        
        def dfs(node):
            if not node:
                return 0
            
            # Compute subtree sum
            subtree_sum = node.val + dfs(node.left) + dfs(node.right)
            
            # Calculate product if we cut above this node
            product = subtree_sum * (total - subtree_sum)
            max_product[0] = max(max_product[0], product)
            
            return subtree_sum
        
        dfs(root)
        
        return max_product[0] % MOD