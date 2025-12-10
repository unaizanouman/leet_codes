class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const int MOD = 1e9 + 7;
        int n = complexity.size();
        
        // Check if all computers are unlockable
        int min_so_far = complexity[0];
        for (int i = 1; i < n; i++) {
            if (min_so_far >= complexity[i]) {
                return 0;
            }
            min_so_far = min(min_so_far, complexity[i]);
        }
        
        // Compute (n-1)! mod MOD
        long long result = 1;
        for (int i = 1; i < n; i++) {
            result = result * i % MOD;
        }
        
        return result;
    }
};