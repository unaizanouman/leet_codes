class Solution {
public:
    int reverse(int x) {
        long long rev = 0;  // use long long to detect overflow during calculation
        while (x != 0) {
            int digit = x % 10;   // get last digit
            rev = rev * 10 + digit;
            x /= 10;  // remove last digit
        }
        
        // check 32-bit signed int overflow
        if (rev > INT_MAX || rev < INT_MIN) return 0;
        
        return (int)rev;
    }
};
