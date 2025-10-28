class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m=g.size(),n=g[0].size();
        vector<vector<long>>dp(m,vector<long>(n,0));
        if(g[0][0]==1)return 0;
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]==1){dp[i][j]=0;continue;}
                if(i>0)dp[i][j]+=dp[i-1][j];
                if(j>0)dp[i][j]+=dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
