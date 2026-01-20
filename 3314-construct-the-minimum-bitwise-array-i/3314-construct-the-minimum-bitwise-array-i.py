class Solution:
    def minBitwiseArray(self, nums):
        ans=[]
        for i in range(len(nums)):

            target=nums[i]
            found=False

            for x in range(target):

                if (x|(x+1))==target:
                    ans.append(x)
                    found=True
                    break

            if found==False:
                ans.append(-1)

        return ans