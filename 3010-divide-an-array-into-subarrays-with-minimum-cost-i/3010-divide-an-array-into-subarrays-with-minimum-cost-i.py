class Solution:
    def minimumCost(self,nums):

        n=len(nums)
        ans=10**9
        for i in range(1,n-1):
            for j in range(i+1,n):
                cost=nums[0]+nums[i]+nums[j]
                if cost<ans:
                    ans=cost
        return ans