class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        long long twoColor = 6;  
        long long threeColor = 6;

        for (int i = 2; i <= n; i++) {
            long long newTwo = (twoColor * 3 + threeColor * 2) % MOD;
            long long newThree = (twoColor * 2 + threeColor * 2) % MOD;
            twoColor = newTwo;
            threeColor = newThree;
        }

        return (twoColor + threeColor) % MOD;
    }
};
