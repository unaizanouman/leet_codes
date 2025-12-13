class Solution:
    def isInterleave(self, s1, s2, s3):
        m, n = len(s1), len(s2)

        if m + n != len(s3):
            return False

        dp = [False] * (n + 1)
        dp[0] = True

        # First row (only s2)
        for j in range(1, n + 1):
            dp[j] = dp[j - 1] and s2[j - 1] == s3[j - 1]

        for i in range(1, m + 1):
            # First column (only s1)
            dp[0] = dp[0] and s1[i - 1] == s3[i - 1]

            for j in range(1, n + 1):
                dp[j] = (
                    (dp[j] and s1[i - 1] == s3[i + j - 1]) or
                    (dp[j - 1] and s2[j - 1] == s3[i + j - 1])
                )

        return dp[n]
