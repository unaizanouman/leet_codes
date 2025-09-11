class Solution {
public:
    string sortVowels(string s) {
        // Step 1: Collect all vowels
        vector<char> vowels;
        string vowelSet = "aeiouAEIOU";
        
        for (char c : s) {
            if (vowelSet.find(c) != string::npos) {
                vowels.push_back(c);
            }
        }
        
        // Step 2: Sort vowels
        sort(vowels.begin(), vowels.end());
        
        // Step 3: Replace vowels back in string
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (vowelSet.find(s[i]) != string::npos) {
                s[i] = vowels[j++];
            }
        }
        
        return s;
    }
};
