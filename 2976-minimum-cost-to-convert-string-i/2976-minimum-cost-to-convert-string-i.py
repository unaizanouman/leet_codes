class Solution:
    def minimumCost(self,source,target,original,changed,cost):

        INF=10**18
        dist=[[INF]*26 for _ in range(26)]

        for i in range(26):
            dist[i][i]=0
        for i in range(len(original)):
            u=ord(original[i])-97
            v=ord(changed[i])-97
            if cost[i]<dist[u][v]:
                dist[u][v]=cost[i]

        # floyd warshall
        for k in range(26):
            for i in range(26):
                for j in range(26):
                    if dist[i][k]+dist[k][j]<dist[i][j]:
                        dist[i][j]=dist[i][k]+dist[k][j]
        ans=0

        for i in range(len(source)):
            a=ord(source[i])-97
            b=ord(target[i])-97

            if dist[a][b]==INF:
                return -1
            ans+=dist[a][b]
        return ans