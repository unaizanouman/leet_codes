class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        res.push_back(words[0]);
        for (int i = 1; i < words.size(); i++) {
            string a = words[i], b = res.back();
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            if (a != b) res.push_back(words[i]);
        }
        return res;
    }
};
