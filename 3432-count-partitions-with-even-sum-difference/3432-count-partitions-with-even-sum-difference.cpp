class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = 0;
        for (int x : nums) total += x;
        if (total % 2 != 0) return 0;
        return nums.size() - 1; 
    }
};
