class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
    
    void backtrack(vector<string>& result, string current, int open, int close, int maxPairs) {
        // If the current string is complete, add it
        if (current.size() == maxPairs * 2) {
            result.push_back(current);
            return;
        }

        // Add an opening parenthesis if we still have some left
        if (open < maxPairs) {
            backtrack(result, current + "(", open + 1, close, maxPairs);
        }

        // Add a closing parenthesis if it won’t break validity
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, maxPairs);
        }
    }
};
