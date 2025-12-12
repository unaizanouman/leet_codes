class Solution:
    def numTrees(self, n):
        dp = [0] * (n + 1)
        dp[0] = dp[1] = 1  # Base cases

        for nodes in range(2, n + 1):
            total = 0
            for root in range(1, nodes + 1):
                left = root - 1
                right = nodes - root
                total += dp[left] * dp[right]
            dp[nodes] = total

        return dp[n]
