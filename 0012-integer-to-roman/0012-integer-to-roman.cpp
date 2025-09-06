class Solution {
public:
    string intToRoman(int num) {
        // Values and their corresponding Roman numerals
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string result = "";
        
        for (int i = 0; i < values.size(); i++) {
            while (num >= values[i]) {
                num -= values[i];       // subtract value
                result += symbols[i];   // append symbol
            }
        }
        return result;
    }
};
