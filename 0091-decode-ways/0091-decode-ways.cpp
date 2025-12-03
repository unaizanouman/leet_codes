#include <string>
#include <vector>

class Solution {
public:
    int numDecodings(std::string s) {
        int n = s.length();
        if (n == 0 || s[0] == '0') {
            return 0;
        }
        long long two_back = 1;
        long long one_back = 1;

        for (int i = 2; i <= n; ++i) {
            long long current = 0;
            char single_digit = s[i-1];
            if (single_digit != '0') {
                current += one_back;
            }
            char first_digit = s[i-2];
            char second_digit = s[i-1];
            if (first_digit == '1') {
                current += two_back;
            } 
            else if (first_digit == '2') {
                if (second_digit >= '0' && second_digit <= '6') {
                    current += two_back;
                }
            }
            if (current == 0) {
                return 0; 
            }
            two_back = one_back;
            one_back = current;
        }

        return (int)one_back;
    }
};