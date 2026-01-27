import heapq

class Solution:
    def minCost(self,n,edges):

        graph=[[] for _ in range(n)]

        for u,v,w in edges:
            graph[u].append((v,w))       # normal edge
            graph[v].append((u,2*w))     # reversed edge

        INF=10**18
        dist=[INF]*n
        dist[0]=0

        pq=[]
        heapq.heappush(pq,(0,0))

        while pq:
            cost,u=heapq.heappop(pq)

            if cost>dist[u]:
                continue

            for v,w in graph[u]:
                if dist[v]>cost+w:
                    dist[v]=cost+w
                    heapq.heappush(pq,(dist[v],v))

        if dist[n-1]==INF:
            return -1
        return dist[n-1]
