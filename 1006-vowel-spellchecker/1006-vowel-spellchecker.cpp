class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelInsensitive;

        auto devowel = [](string s) {
            for (char &c : s) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') c = '*';
            }
            return s;
        };

        // Preprocess wordlist
        for (string w : wordlist) {
            string lower = w;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

            if (!caseInsensitive.count(lower)) 
                caseInsensitive[lower] = w;

            string dev = devowel(lower);
            if (!vowelInsensitive.count(dev)) 
                vowelInsensitive[dev] = w;
        }

        vector<string> ans;
        for (string q : queries) {
            if (exact.count(q)) {
                ans.push_back(q);
                continue;
            }

            string lower = q;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

            if (caseInsensitive.count(lower)) {
                ans.push_back(caseInsensitive[lower]);
                continue;
            }

            string dev = devowel(lower);
            if (vowelInsensitive.count(dev)) {
                ans.push_back(vowelInsensitive[dev]);
                continue;
            }

            ans.push_back("");
        }
        return ans;
    }
};
