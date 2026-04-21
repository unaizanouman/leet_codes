class Solution:
    def minimumHammingDistance(self,source,target,allowedSwaps):
        parent=list(range(len(source)))
        def find(x):
            if parent[x]!=x:
                parent[x]=find(parent[x])
            return parent[x]
        def union(x,y):
            parent[find(x)]=find(y)
        for a,b in allowedSwaps:
            union(a,b)
        from collections import defaultdict
        groups=defaultdict(list)
        for i in range(len(source)):
            groups[find(i)].append(i)
        ans=0
        for g in groups.values():
            cnt={}
            for i in g:
                cnt[source[i]]=cnt.get(source[i],0)+1
            for i in g:
                if cnt.get(target[i],0)>0:
                    cnt[target[i]]-=1
                else:
                    ans+=1
        return ans