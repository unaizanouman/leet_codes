class Solution:
    def minimumDifference(self,nums,k):

        nums.sort()
        ans=10**9
        for i in range(len(nums)-k+1):
            diff=nums[i+k-1]-nums[i]
            if diff<ans:
                ans=diff

        return ans