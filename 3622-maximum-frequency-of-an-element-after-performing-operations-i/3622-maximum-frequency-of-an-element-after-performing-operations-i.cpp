class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int,int> cnt;
        map<long long,int> d;
        for (int v : nums) {
            cnt[v]++;
            d[v] += 0;
            d[v - k] += 1;
            d[(long long)v + k + 1] -= 1;
        }
        int ans = 0;
        long long s = 0;
        for (auto &p : d) {
            long long x = p.first;
            int delta = p.second;
            s += delta;
            int already = cnt.count(x) ? cnt[x] : 0;
            int freq = min( (long long)s, (long long)already + numOperations );
            ans = max(ans, freq);
        }
        return ans;
    }
};
