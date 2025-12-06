class Solution {
public:
    static const long long MOD = 1000000007;

    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n, 0), pref(n, 0);
        deque<int> maxd, mind; 

        int l = 0;
        for (int i = 0; i < n; i++) {
            while (!maxd.empty() && nums[maxd.back()] <= nums[i])
                maxd.pop_back();
            maxd.push_back(i);
            while (!mind.empty() && nums[mind.back()] >= nums[i])
                mind.pop_back();
            mind.push_back(i);
            while (!maxd.empty() && !mind.empty() &&
                   nums[maxd.front()] - nums[mind.front()] > k) {
                if (maxd.front() == l) maxd.pop_front();
                if (mind.front() == l) mind.pop_front();
                l++;
            }
            if (l == 0) {
                dp[i] = (i == 0 ? 1 : (pref[i-1] + 1) % MOD);
            } else {
                long long leftSum = pref[i-1];
                long long remove = (l >= 2 ? pref[l-2] : 0);
                dp[i] = (leftSum - remove + MOD) % MOD;
            }
            pref[i] = dp[i];
            if (i > 0) pref[i] = (pref[i] + pref[i-1]) % MOD;
        }
        return dp[n-1];
    }
};
