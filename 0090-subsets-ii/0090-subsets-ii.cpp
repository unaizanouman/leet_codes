class Solution {
public:
    vector<vector<int>> res;
    vector<int> curr;
    void backtrack(vector<int>& nums, int start) {
        res.push_back(curr);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;

            curr.push_back(nums[i]);
            backtrack(nums, i + 1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // important!
        backtrack(nums, 0);
        return res;
    }
};
