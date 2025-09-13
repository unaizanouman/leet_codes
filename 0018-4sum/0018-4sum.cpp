class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // avoid duplicates for i
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // avoid duplicates for j
                
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                int left = j + 1, right = n - 1;
                
                while (left < right) {
                    long long sum = (long long)nums[left] + (long long)nums[right];
                    if (sum == newTarget) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // skip duplicates
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        
                        left++;
                        right--;
                    } 
                    else if (sum < newTarget) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return res;
    }
};
