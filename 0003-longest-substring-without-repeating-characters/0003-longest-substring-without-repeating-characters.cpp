#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
int lengthOfLongestSubstring(string s) {
unordered_set<char> window;
int left = 0, right = 0, maxLen = 0;


while (right < s.size()) {
// If char not in set, expand window
if (window.find(s[right]) == window.end()) {
window.insert(s[right]);
maxLen = max(maxLen, (int)window.size());
right++;
} else {
// Remove left char to handle duplicate
window.erase(s[left]);
left++;
}
}
return maxLen;
}
};