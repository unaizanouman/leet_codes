class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long base = 0;

        // Base profit (no modification)
        for (int i = 0; i < n; i++) {
            base += 1LL * strategy[i] * prices[i];
        }

        int half = k / 2;
        long long gain = 0, best = 0;

        // First window
        for (int i = 0; i < k; i++) {
            if (i < half) {
                // becomes 0
                gain -= 1LL * strategy[i] * prices[i];
            } else {
                // becomes +1
                gain += 1LL * prices[i] - 1LL * strategy[i] * prices[i];
            }
        }
        best = gain;

        // Slide window
        for (int l = 1; l + k - 1 < n; l++) {
            int r = l + k - 1;

            // remove left element (was in first half)
            gain += 1LL * strategy[l - 1] * prices[l - 1];

            // middle element shifts halves
            int mid = l + half - 1;
            gain -= 1LL * prices[mid];

            // add right element (new second half)
            gain += 1LL * prices[r] - 1LL * strategy[r] * prices[r];

            best = max(best, gain);
        }

        // IMPORTANT FIX
        return base + max(0LL, best);
    }
};
