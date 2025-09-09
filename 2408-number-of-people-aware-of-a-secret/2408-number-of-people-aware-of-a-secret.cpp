class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;

        vector<long long> dp(n + 1, 0);  // dp[i] = number of people who learn the secret on day i
        dp[1] = 1; // Day 1, first person knows the secret

        long long peopleSharing = 0; // people who can currently share the secret

        for (int day = 2; day <= n; day++) {
            // Add people who can start sharing today
            if (day - delay >= 1) {
                peopleSharing = (peopleSharing + dp[day - delay]) % MOD;
            }

            // Remove people who forget today
            if (day - forget >= 1) {
                peopleSharing = (peopleSharing - dp[day - forget] + MOD) % MOD;
            }

            // People who learn the secret today = all currently sharing
            dp[day] = peopleSharing;
        }

        // Count people who still remember at day n
        long long result = 0;
        for (int day = n - forget + 1; day <= n; day++) {
            if (day >= 1) result = (result + dp[day]) % MOD;
        }

        return result;
    }
};
