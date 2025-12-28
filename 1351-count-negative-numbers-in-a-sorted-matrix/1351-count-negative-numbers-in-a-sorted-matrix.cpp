class Solution{
public:
    int countNegatives(vector<vector<int>>& grid){
        int m=grid.size(), n=grid[0].size();
        int r=0,c=n-1,ans=0;
        while(r<m&&c>=0){
            if(grid[r][c]<0){
                ans+=m-r;
                c--;
            }else r++;
        }
        return ans;
    }
};
