class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 2; i <= n; i++) {
            string cur = "";
            int count = 1;
            for (int j = 1; j <= res.size(); j++) {
                if (j < res.size() && res[j] == res[j - 1]) {
                    count++;
                } else {
                    cur += to_string(count) + res[j - 1];
                    count = 1;
                }
            }
            res = cur;
        }
        return res;
    }
};
