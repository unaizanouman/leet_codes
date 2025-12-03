#include <string>
#include <vector>

class Solution {
public:
    int numDecodings(std::string s) {
        int n = s.length();
        if (n == 0 || s[0] == '0') {
            return 0;
        }

        // two_back = DP[i-2], initialized to DP[0] = 1 (empty string)
        // one_back = DP[i-1], initialized to DP[1] = 1 (single valid character)
        long long two_back = 1;
        long long one_back = 1;

        for (int i = 2; i <= n; ++i) {
            long long current = 0;
            
            // 1. Contribution from 1-way split: s[i-1]
            // Valid if s[i-1] is not '0'.
            char single_digit = s[i-1];
            if (single_digit != '0') {
                current += one_back;
            }

            // 2. Contribution from 2-way split: s[i-2]s[i-1]
            // Valid if the two-digit number is between 10 and 26.
            char first_digit = s[i-2];
            char second_digit = s[i-1];

            // Check for '1x' (10-19)
            if (first_digit == '1') {
                current += two_back;
            } 
            // Check for '2x' (20-26)
            else if (first_digit == '2') {
                if (second_digit >= '0' && second_digit <= '6') {
                    current += two_back;
                }
            }

            // If current is 0, no valid decoding exists.
            if (current == 0) {
                return 0; 
            }

            // Shift DP states: DP[i-2] <- DP[i-1], DP[i-1] <- DP[i]
            two_back = one_back;
            one_back = current;
        }

        return (int)one_back; // one_back holds DP[n]
    }
};