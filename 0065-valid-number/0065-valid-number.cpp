class Solution {
public:
    bool isNumber(string s) {
        bool num = false, dot = false, exp = false;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char c = s[i];
            
            if (isdigit(c)) {
                num = true;
            } 
            else if (c == '.') {
                if (dot || exp) return false;
                dot = true;
            } 
            else if (c == 'e' || c == 'E') {
                if (exp || !num) return false;
                exp = true;
                num = false;
            } 
            else if (c == '+' || c == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            } 
            else {
                return false;
            }
        }
        return num;
    }
};
