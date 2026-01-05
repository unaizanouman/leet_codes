class Solution{
public:
    long long maxMatrixSum(vector<vector<int>>& matrix){
        long long sum=0;
        int neg=0;
        int mn=INT_MAX;
        
        for(auto &r:matrix){
            for(int x:r){
                if(x<0)neg++;
                sum+=abs(x);
                mn=min(mn,abs(x));
            }
        }
        
        if(neg%2)sum-=2LL*mn;
        return sum;
    }
};
