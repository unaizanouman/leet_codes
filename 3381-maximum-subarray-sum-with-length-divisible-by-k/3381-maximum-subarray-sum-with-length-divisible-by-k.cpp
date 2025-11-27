class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long pref = 0;
        long long best = LLONG_MIN;

        vector<long long> min_pref(k, LLONG_MAX);
        min_pref[0] = 0;

        for (int i = 1; i <= n; i++) {
            pref += nums[i - 1];
            int mod = i % k;

            // Only compute if valid
            if (min_pref[mod] != LLONG_MAX) {
                best = max(best, pref - min_pref[mod]);
            }

            // Update min prefix
            min_pref[mod] = min(min_pref[mod], pref);
        }

        return best;
    }
};
