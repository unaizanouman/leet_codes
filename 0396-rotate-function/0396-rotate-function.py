class Solution:
    def maxRotateFunction(self, nums):
        n=len(nums)
        s=sum(nums)
        f=sum(i*nums[i] for i in range(n))
        ans=f
        for i in range(n-1,0,-1):
            f=f+s-n*nums[i]
            if f>ans:ans=f
        return ans