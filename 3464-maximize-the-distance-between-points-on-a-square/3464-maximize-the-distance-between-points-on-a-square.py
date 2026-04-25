class Solution:
    def maxDistance(self,side,points,k):
        import bisect
        def check(n,res,k,side):
            m=len(res)
            idx=[0]*k
            curr=res[0]
            idx[0]=0
            for i in range(1,k):
                j=bisect.bisect_left(res,curr+n)
                if j==m:
                    return False
                idx[i]=j
                curr=res[j]
            if res[idx[k-1]]-res[0]<=4*side-n:
                return True
            idx[0]=1
            while idx[0]<idx[1]:
                for j in range(1,k):
                    while idx[j]<m and res[idx[j]]<res[idx[j-1]]+n:
                        idx[j]+=1
                    if idx[j]==m:
                        return False
                if res[idx[k-1]]-res[idx[0]]<=4*side-n:
                    return True
                idx[0]+=1
            return False
        res=[]
        for x,y in points:
            if x==0:res.append(y)
            elif y==side:res.append(side+x)
            elif x==side:res.append(3*side-y)
            else:res.append(4*side-x)
        res.sort()
        left=1
        right=(4*side)//k+1
        ans=0
        while left<=right:
            mid=(left+right)//2
            if check(mid,res,k,side):
                ans=mid
                left=mid+1
            else:
                right=mid-1
        return ans