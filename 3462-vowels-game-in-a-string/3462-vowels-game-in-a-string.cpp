class Solution {
public:
    bool doesAliceWin(string s) {
        string vowels = "aeiou";
        for (char c : s) {
            if (vowels.find(c) != string::npos) {
                return true;  // Alice can start by removing one vowel
            }
        }
        return false; // No vowels -> Alice cannot move
    }
};
