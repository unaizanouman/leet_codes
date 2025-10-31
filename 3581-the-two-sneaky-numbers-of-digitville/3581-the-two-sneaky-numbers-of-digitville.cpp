class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans; 
        unordered_map<int,int> mp;
        for(int x:nums) mp[x]++;
        for(auto &p:mp)
            if(p.second==2) ans.push_back(p.first);
        return ans;
    }
};
