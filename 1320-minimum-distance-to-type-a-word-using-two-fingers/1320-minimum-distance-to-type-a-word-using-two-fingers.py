class Solution:
    def getDistance(self,p,q):
        x1,y1=p//6,p%6
        x2,y2=q//6,q%6
        return abs(x1-x2)+abs(y1-y2)
    def minimumDistance(self,word):
        n=len(word)
        INF=10**9
        dp=[[[INF]*26 for _ in range(26)] for _ in range(n)]
        for i in range(26):
            dp[0][i][ord(word[0])-65]=0
            dp[0][ord(word[0])-65][i]=0
        for i in range(1,n):
            cur=ord(word[i])-65
            prev=ord(word[i-1])-65
            d=self.getDistance(prev,cur)
            for j in range(26):
                dp[i][cur][j]=min(dp[i][cur][j],dp[i-1][prev][j]+d)
                dp[i][j][cur]=min(dp[i][j][cur],dp[i-1][j][prev]+d)
                if prev==j:
                    for k in range(26):
                        d0=self.getDistance(k,cur)
                        dp[i][cur][j]=min(dp[i][cur][j],dp[i-1][k][j]+d0)
                        dp[i][j][cur]=min(dp[i][j][cur],dp[i-1][j][k]+d0)
        ans=INF
        for i in range(26):
            for j in range(26):
                ans=min(ans,dp[n-1][i][j])
        return ans