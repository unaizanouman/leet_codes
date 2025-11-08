class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0) return 0;
        int highestBit = 31 - __builtin_clz(n);  // find the position of the highest set bit
        int mask = 1 << highestBit;
        return (1 << (highestBit + 1)) - 1 - minimumOneBitOperations(n ^ mask);
    }
};
