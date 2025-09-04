class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are never palindromes
        if (x < 0) return false;

        // Numbers ending with 0 (but not 0 itself) are not palindromes
        if (x % 10 == 0 && x != 0) return false;

        int reversedHalf = 0;

        // Reverse only half of the number
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // Palindrome if original half == reversed half
        // OR (when odd length) original half == reversedHalf/10
        return (x == reversedHalf || x == reversedHalf / 10);
    }
};
