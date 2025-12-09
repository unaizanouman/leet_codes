#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const long long MOD = 1000000007;

    int specialTriplets(vector<int>& nums) {
        unordered_map<int, long long> right, left;
        int n = nums.size();
        for (int x : nums) right[x]++;

        long long ans = 0;
        for (int j = 0; j < n; ++j) {
            int x = nums[j];
            right[x]--;  
            long long target = 2LL * x;
            if (left.count((int)target) && right.count((int)target)) {
                ans = (ans + left[(int)target] * right[(int)target]) % MOD;
            }
            left[x]++;                      
        }

        return (int)ans;
    }
};
