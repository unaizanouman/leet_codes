class Solution:
    def minBitwiseArray(self, nums):

        ans=[]
        for i in range(len(nums)):
            p=nums[i]

            if p==2:
                ans.append(-1)
            else:
                c=0
                temp=p
                while temp&1==1:
                    c=c+1
                    temp=temp>>1
                ans.append(p-(1<<(c-1)))
        return ans