class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long sum = 0;
        for (int x : nums) sum += x;
        
        int rem = sum % k;
        if (rem == 0) return 0;
        return rem;  
    }
};
