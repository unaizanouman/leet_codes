class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (i > maxReach) return false;  // can't move beyond this point
            maxReach = max(maxReach, i + nums[i]);
            if (maxReach >= n - 1) return true;  // can reach or go beyond last index
        }
        return true;
    }
};
