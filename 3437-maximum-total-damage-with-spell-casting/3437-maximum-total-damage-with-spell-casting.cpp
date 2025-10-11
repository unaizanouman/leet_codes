class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int,long long> freq;
        for(int p:power) freq[p]+=p; // total damage for same power values
        
        vector<long long> vals;
        for(auto &x:freq) vals.push_back(x.first);
        sort(vals.begin(),vals.end());
        
        int n=vals.size();
        vector<long long> dp(n,0);
        dp[0]=freq[vals[0]];
        
        for(int i=1;i<n;i++){
            long long take=freq[vals[i]];
            int j=i-1;
            // find previous value not in [vals[i]-2, vals[i]-1, vals[i]+1, vals[i]+2]
            while(j>=0 && vals[i]-vals[j]<=2) j--;
            if(j>=0) take+=dp[j];
            dp[i]=max(dp[i-1],take);
        }
        
        return dp[n-1];
    }
};
