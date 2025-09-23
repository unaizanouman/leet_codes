#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLen = words[0].size();   
        int wordCount = words.size();   
        int totalLen = wordLen * wordCount; 

        if (s.size() < totalLen) return result;

        unordered_map<string, int> wordFreq;
        for (string& w : words) {
            wordFreq[w]++;
        }

        for (int i = 0; i < wordLen; i++) {
            int left = i, right = i;
            unordered_map<string, int> seen;
            int count = 0; 

            while (right + wordLen <= s.size()) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordFreq.count(word)) {
                    seen[word]++;
                    count++;

                    while (seen[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        return result;
    }
};
