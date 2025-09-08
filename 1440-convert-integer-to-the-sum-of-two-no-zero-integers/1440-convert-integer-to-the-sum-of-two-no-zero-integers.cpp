class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; a++) {
            int b = n - a;
            if (isNoZero(a) && isNoZero(b)) {
                return {a, b};
            }
        }
        return {}; // should never reach here because solution always exists
    }

private:
    bool isNoZero(int num) {
        while (num > 0) {
            if (num % 10 == 0) return false; // contains zero
            num /= 10;
        }
        return true;
    }
};
