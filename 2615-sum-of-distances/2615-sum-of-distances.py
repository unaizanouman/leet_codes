class Solution:
    def distance(self,nums):
        from collections import defaultdict
        pos=defaultdict(list)
        for i,v in enumerate(nums):
            pos[v].append(i)
        res=[0]*len(nums)
        for arr in pos.values():
            prefix=[0]
            for x in arr:
                prefix.append(prefix[-1]+x)
            n=len(arr)
            for i,x in enumerate(arr):
                left=x*i-prefix[i]
                right=(prefix[n]-prefix[i+1])-(n-i-1)*x
                res[x]=left+right
        return res