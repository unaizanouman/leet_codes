#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long last = LLONG_MIN;
        int distinct = 0;

        for (long long num : nums) {
            long long candidate = max(num - k, last + 1);
            if (candidate <= num + k) {
                distinct++;
                last = candidate;
            }
        }
        return distinct;
    }
};
