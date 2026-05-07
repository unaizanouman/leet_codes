class Solution:
    def maxValue(self, nums):
        n=len(nums)
        suf=[0]*n
        suf[-1]=nums[-1]
        for i in range(n-2,-1,-1):
            suf[i]=min(nums[i],suf[i+1])
        ans=[0]*n
        l=0
        mx=nums[0]
        for i in range(n):
            mx=max(mx,nums[i])
            if i==n-1 or mx<=suf[i+1]:
                for j in range(l,i+1):
                    ans[j]=mx
                l=i+1
                if i+1<n:
                    mx=nums[i+1]
        return ans