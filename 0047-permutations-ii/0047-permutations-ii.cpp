class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int>temp;
        vector<bool>used(nums.size(),false);
        function<void()>backtrack=[&](){
            if(temp.size()==nums.size()){
                res.push_back(temp);
                return;
            }
            for(int i=0;i<nums.size();i++){
                if(used[i]||(i>0&&nums[i]==nums[i-1]&&!used[i-1]))continue;
                used[i]=true;
                temp.push_back(nums[i]);
                backtrack();
                used[i]=false;
                temp.pop_back();
            }
        };
        backtrack();
        return res;
    }
};
