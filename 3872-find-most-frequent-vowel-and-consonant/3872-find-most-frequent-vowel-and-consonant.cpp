class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> freq;
        string vowels = "aeiou";
        unordered_set<char> vowelSet(vowels.begin(), vowels.end());

        int maxVowel = 0, maxCons = 0;

        for (char c : s) {
            freq[c]++;
        }

        for (auto &p : freq) {
            if (vowelSet.count(p.first)) {
                maxVowel = max(maxVowel, p.second);
            } else {
                maxCons = max(maxCons, p.second);
            }
        }

        return maxVowel + maxCons;
    }
};
