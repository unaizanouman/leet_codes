class Solution{
    unordered_map<string, vector<char>> mp;
    unordered_map<string, bool> memo;

    bool dfs(string curr){
        if(curr.size()==1) return true;
        if(memo.count(curr)) return memo[curr];

        bool res = build(curr,0,"");
        return memo[curr] = res;
    }

    bool build(string &curr,int idx,string next){
        if(idx==curr.size()-1)
            return dfs(next);

        string key;
        key+=curr[idx];
        key+=curr[idx+1];

        if(!mp.count(key)) return false;

        for(char c:mp[key]){
            if(build(curr,idx+1,next+c))
                return true;
        }
        return false;
    }

public:
    bool pyramidTransition(string bottom, vector<string>& allowed){
        for(auto &s:allowed)
            mp[s.substr(0,2)].push_back(s[2]);

        return dfs(bottom);
    }
};
