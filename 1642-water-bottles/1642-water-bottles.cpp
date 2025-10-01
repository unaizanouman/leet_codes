class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles, empty = numBottles;
        while (empty >= numExchange) {
            int newBottles = empty / numExchange;
            ans += newBottles;
            empty = empty % numExchange + newBottles;
        }
        return ans;
    }
};
