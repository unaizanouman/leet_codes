class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
        int m=g.size(),n=g[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(i==0&&j==0) continue;
                int up=i>0?g[i-1][j]:1e9;
                int left=j>0?g[i][j-1]:1e9;
                g[i][j]+=min(up,left);
            }
        return g[m-1][n-1];
    }
};
