# Definition for a binary tree node.
# (LeetCode provides this class automatically)

class Solution:
    def generateTrees(self, n):
        if n == 0:
            return []

        memo = {}

        def generate(l, r):
            if l > r:
                return [None]
            if (l, r) in memo:
                return memo[(l, r)]

            res = []
            for root_val in range(l, r + 1):
                left_trees = generate(l, root_val - 1)
                right_trees = generate(root_val + 1, r)

                for L in left_trees:
                    for R in right_trees:
                        root = TreeNode(root_val)
                        root.left = L
                        root.right = R
                        res.append(root)

            memo[(l, r)] = res
            return res

        return generate(1, n)
