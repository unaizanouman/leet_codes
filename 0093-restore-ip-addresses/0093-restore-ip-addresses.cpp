class Solution {
public:
    vector<string> result;
    vector<string> path;

    bool valid(const string &s) {
        if (s.size() > 1 && s[0] == '0') return false; 
        if (s.size() > 3) return false;
        int val = stoi(s);
        return val >= 0 && val <= 255;
    }

    void backtrack(string &s, int idx) {
        if (path.size() == 4) {
            if (idx == s.size()) {
                result.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
            }
            return;
        }

        for (int len = 1; len <= 3 && idx + len <= s.size(); len++) {
            string part = s.substr(idx, len);
            if (valid(part)) {
                path.push_back(part);
                backtrack(s, idx + len);
                path.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        result.clear();
        path.clear();
        backtrack(s, 0);
        return result;
    }
};
