class Solution:
    def solveQueries(self,nums,queries):
        from collections import defaultdict
        n=len(nums)
        pos=defaultdict(list)
        for i,v in enumerate(nums):
            pos[v].append(i)
        res=[]
        for q in queries:
            arr=pos[nums[q]]
            if len(arr)==1:
                res.append(-1)
                continue
            import bisect
            i=bisect.bisect_left(arr,q)
            left=arr[i-1] if i>0 else arr[-1]
            right=arr[i+1] if i<len(arr)-1 else arr[0]
            d1=abs(q-left)
            d2=abs(q-right)
            res.append(min(d1,n-d1,d2,n-d2))
        return res