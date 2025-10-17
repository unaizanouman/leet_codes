class Solution {
public:
    string s;
    int n, K;
    unordered_map<long long, int> memo;
    
    int dfs(int i, int mask, int t) {
        if (i == n) {
            return 1;
        }
        long long key = ((long long)i << 32) | ((long long)mask << 1) | t;
        if (memo.count(key)) return memo[key];
        
        int v = 1 << (s[i] - 'a');
        int newMask = mask | v;
        int res;
        
        if (__builtin_popcount(newMask) > K) {
            // must start new partition
            res = 1 + dfs(i + 1, v, t);
        } else {
            // can stay in current partition
            res = dfs(i + 1, newMask, t);
        }
        
        if (t == 1) {
            // Try changing s[i] to some other letter
            for (int c = 0; c < 26; c++) {
                int u = 1 << c;
                if (u == v) continue;  // skip same letter (optional)
                int newMask2 = mask | u;
                if (__builtin_popcount(newMask2) > K) {
                    res = max(res, 1 + dfs(i + 1, u, 0));
                } else {
                    res = max(res, dfs(i + 1, newMask2, 0));
                }
            }
        }
        
        return memo[key] = res;
    }
    
    int maxPartitionsAfterOperations(string _s, int k) {
        s = _s;
        n = s.size();
        K = k;
        memo.clear();
        return dfs(0, 0, 1);
    }
};
