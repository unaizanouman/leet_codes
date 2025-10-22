#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        unordered_map<long long,int> cnt;
        map<long long,long long> diff; // sorted keys
        
        for (long long v : nums) {
            cnt[v]++;
            diff[v - k] += 1;
            diff[v + k + 1] -= 1;
            diff[v] += 0; // ensure v is a key so we evaluate target v
        }
        
        long long s = 0;
        int ans = 0;
        for (auto &p : diff) {
            long long x = p.first;
            s += p.second;
            int already = cnt.count(x) ? cnt[x] : 0;
            long long freq = min(s, (long long)already + numOperations);
            ans = max(ans, (int)freq);
        }
        return ans;
    }
};
