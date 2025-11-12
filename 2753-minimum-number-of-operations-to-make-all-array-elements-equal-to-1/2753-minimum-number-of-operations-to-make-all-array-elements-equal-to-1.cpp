#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int overall_gcd = nums[0];
        for (int x : nums)
            overall_gcd = gcd(overall_gcd, x);
        if (overall_gcd != 1)
            return -1;
        int ones = count(nums.begin(), nums.end(), 1);
        if (ones > 0)
            return n - ones;
        int minLen = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int g = nums[i];
            for (int j = i + 1; j < n; ++j) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }
        return (minLen - 1) + (n - 1);
    }
};
