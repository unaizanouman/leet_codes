class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        vector<int> fact(n + 1, 1);
        
        // Precompute factorials
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
            nums.push_back(i);
        }
        
        k--; // make k zero-based
        string result = "";
        
        for (int i = n; i >= 1; i--) {
            int idx = k / fact[i - 1];
            k %= fact[i - 1];
            
            result += to_string(nums[idx]);
            nums.erase(nums.begin() + idx);
        }
        
        return result;
    }
};
