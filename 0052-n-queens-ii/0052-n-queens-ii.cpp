class Solution{
public:
    int totalNQueens(int n){
        int count=0;
        vector<int>col(n,0),diag1(2*n,0),diag2(2*n,0);
        function<void(int)>dfs=[&](int r){
            if(r==n){count++;return;}
            for(int c=0;c<n;c++){
                if(col[c]||diag1[r+c]||diag2[r-c+n])continue;
                col[c]=diag1[r+c]=diag2[r-c+n]=1;
                dfs(r+1);
                col[c]=diag1[r+c]=diag2[r-c+n]=0;
            }
        };
        dfs(0);
        return count;
    }
};
