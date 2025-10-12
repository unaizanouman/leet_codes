class Solution {
public:
    int magicalSum(int m,int k,vector<int>& nums) {
        const long long MOD = 1e9+7;
        int n = nums.size();
        vector<long long> fact(m+1,1), invfact(m+1,1);
        for(int i=1;i<=m;i++) fact[i] = fact[i-1]*i % MOD;
        auto modpow = [&](long long a,long long e){
            long long r=1%MOD;
            while(e){
                if(e&1) r = r*a % MOD;
                a = a*a % MOD;
                e >>= 1;
            }
            return r;
        };
        invfact[m] = modpow(fact[m], MOD-2);
        for(int i=m; i>0; i--) invfact[i-1] = invfact[i]*i % MOD;

        vector<vector<long long>> powNum(n, vector<long long>(m+1,1));
        for(int i=0;i<n;i++) for(int c=1;c<=m;c++)
            powNum[i][c] = powNum[i][c-1] * nums[i] % MOD;

        int K = min(k, m);
        // dp[used][carry][ones] = ways (with factorials factored out)
        vector<vector<vector<long long>>> dp(m+1,
            vector<vector<long long>>(m+1,
                vector<long long>(K+1, 0)));
        dp[0][0][0] = 1;

        for(int i = 0; i < n; i++) {
            vector<vector<vector<long long>>> ndp(m+1,
                vector<vector<long long>>(m+1,
                    vector<long long>(K+1, 0)));
            for(int used = 0; used <= m; used++) {
                for(int carry = 0; carry <= m; carry++) {
                    for(int ones = 0; ones <= K; ones++) {
                        long long val = dp[used][carry][ones];
                        if (val == 0) continue;
                        for(int c = 0; used + c <= m; c++) {
                            int t = c + carry;
                            int bit = t & 1;
                            int newCarry = t >> 1;
                            int newOnes = ones + bit;
                            if (newOnes > K) break;
                            long long add = val * powNum[i][c] % MOD * invfact[c] % MOD;
                            ndp[used+c][newCarry][newOnes] = (ndp[used+c][newCarry][newOnes] + add) % MOD;
                        }
                    }
                }
            }
            dp.swap(ndp);
        }

        long long ans = 0;
        for(int carry = 0; carry <= m; carry++) {
            for(int ones = 0; ones <= K; ones++) {
                long long val = dp[m][carry][ones];
                if (val == 0) continue;
                int total = ones + __builtin_popcount(carry);
                if (total == k) {
                    ans = (ans + val) % MOD;
                }
            }
        }
        ans = ans * fact[m] % MOD;
        return (int)ans;
    }
};
