class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<int>& path, vector<vector<int>>& res, int start) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] <= target) {
                path.push_back(candidates[i]);
                backtrack(candidates, target - candidates[i], path, res, i);
                path.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(candidates, target, path, res, 0);
        return res;
    }
};
