class Solution(object):
    def maxDotProduct(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
class Solution:
    def maxDotProduct(self, nums1, nums2):
        n, m = len(nums1), len(nums2)
        NEG_INF = -10**18
        
        dp = [[NEG_INF] * (m + 1) for _ in range(n + 1)]
        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                product = nums1[i] * nums2[j]
                
                dp[i][j] = max(
                    product,               
                    product + dp[i + 1][j + 1],  
                    dp[i + 1][j],            
                    dp[i][j + 1]                 
                )
        
        return dp[0][0]
