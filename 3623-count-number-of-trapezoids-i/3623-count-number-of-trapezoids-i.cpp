class Solution {
public:
    const long long MOD = 1000000007;

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, long long> mp;
        for (auto &p : points) mp[p[1]]++;
        vector<long long> a;
        for (auto &x : mp) {
            long long c = x.second;
            if (c >= 2) {
                long long val = (c * (c - 1) / 2) % MOD;
                a.push_back(val);
            }
        }
        if (a.size() < 2) return 0;
        long long sum = 0, sumSq = 0;
        for (long long v : a) {
            sum = (sum + v) % MOD;
            sumSq = (sumSq + (v * v) % MOD) % MOD;
        }
        long long ans = ( (sum * sum) % MOD - sumSq + MOD ) % MOD;
        ans = (ans * ((MOD + 1) / 2)) % MOD; 

        return ans;
    }
};
