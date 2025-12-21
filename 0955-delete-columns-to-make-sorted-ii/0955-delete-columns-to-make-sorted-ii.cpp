class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        
        vector<bool> sorted(n - 1, false);
        int ans = 0;

        for (int c = 0; c < m; c++) {
            bool bad = false;

            // Check if this column breaks order
            for (int i = 0; i < n - 1; i++) {
                if (!sorted[i] && strs[i][c] > strs[i + 1][c]) {
                    bad = true;
                    break;
                }
            }

            if (bad) {
                ans++;
                continue;
            }

            // Update sorted pairs
            for (int i = 0; i < n - 1; i++) {
                if (!sorted[i] && strs[i][c] < strs[i + 1][c]) {
                    sorted[i] = true;
                }
            }
        }

        return ans;
    }
};
