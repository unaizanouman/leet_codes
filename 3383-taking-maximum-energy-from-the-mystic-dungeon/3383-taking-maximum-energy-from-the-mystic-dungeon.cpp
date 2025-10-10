class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n);
        int ans = INT_MIN;
        
        // Start from the end because we need future positions (i + k)
        for(int i = n - 1; i >= 0; i--) {
            if(i + k < n)
                dp[i] = energy[i] + dp[i + k];
            else
                dp[i] = energy[i];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
