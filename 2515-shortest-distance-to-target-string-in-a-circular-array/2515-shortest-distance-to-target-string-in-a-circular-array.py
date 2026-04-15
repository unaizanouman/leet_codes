class Solution:
    def closestTarget(self,words,target,startIndex):
        n=len(words)
        ans=float('inf')
        for i,w in enumerate(words):
            if w==target:
                d=abs(i-startIndex)
                ans=min(ans,min(d,n-d))
        return ans if ans!=float('inf') else -1