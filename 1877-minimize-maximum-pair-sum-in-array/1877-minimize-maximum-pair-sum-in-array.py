class Solution:
    def minPairSum(self,nums):

        nums.sort()

        i=0
        j=len(nums)-1
        ans=0

        while i<j:
            s=nums[i]+nums[j]
            if s>ans:
                ans=s
            i=i+1
            j=j-1

        return ans