class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i + 2 * k <= n; i++) {
            bool first = true, second = true;
            for (int j = i + 1; j < i + k; j++)
                if (nums[j] <= nums[j - 1]) first = false;
            for (int j = i + k + 1; j < i + 2 * k; j++)
                if (nums[j] <= nums[j - 1]) second = false;
            if (first && second) return true;
        }
        return false;
    }
};
