class Solution:
    def maxPathScore(self, grid, k):
        m=len(grid);n=len(grid[0])
        dp=[[[-1]*(k+1) for _ in range(n)] for _ in range(m)]
        dp[0][0][0]=0
        for i in range(m):
            for j in range(n):
                for c in range(k+1):
                    if dp[i][j][c]<0:continue
                    for di,dj in ((1,0),(0,1)):
                        ni=i+di;nj=j+dj
                        if ni<m and nj<n:
                            val=grid[ni][nj]
                            nc=c+(1 if val>0 else 0)
                            if nc<=k:
                                dp[ni][nj][nc]=max(dp[ni][nj][nc],dp[i][j][c]+val)
        ans=max(dp[m-1][n-1])
        return ans if ans!=-1 else -1