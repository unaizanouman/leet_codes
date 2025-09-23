#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLen = words[0].size();       // Each word has same length
        int wordCount = words.size();        // Number of words
        int totalLen = wordLen * wordCount;  // Total length to match

        if (s.size() < totalLen) return result;

        // Count frequency of each word in "words"
        unordered_map<string, int> wordFreq;
        for (string& w : words) {
            wordFreq[w]++;
        }

        // Sliding window starting at different positions
        for (int i = 0; i < wordLen; i++) {
            int left = i, right = i; // window boundaries
            unordered_map<string, int> seen; // words seen in current window
            int count = 0; // matched word count

            while (right + wordLen <= s.size()) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                // If word is part of given words
                if (wordFreq.count(word)) {
                    seen[word]++;
                    count++;

                    // If we used a word more times than allowed, move left side
                    while (seen[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    // If all words matched
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
