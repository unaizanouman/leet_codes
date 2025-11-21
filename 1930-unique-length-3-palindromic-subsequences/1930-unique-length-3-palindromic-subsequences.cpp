class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        
        vector<int> first(26, INT_MAX), last(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = max(last[c], i);
        }
        int ans = 0;
        for (int c = 0; c < 26; c++) {
            if (first[c] == INT_MAX || last[c] == -1 || first[c] == last[c])
                continue; 
            
            vector<bool> seen(26, false);
            
            for (int i = first[c] + 1; i < last[c]; i++) {
                seen[s[i] - 'a'] = true;
            }
            
            ans += count(seen.begin(), seen.end(), true);
        }
        
        return ans;
    }
};
