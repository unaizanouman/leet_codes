class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int totalDrunk = 0;  // total bottles drunk
        int empty = 0;       // empty bottles count

        // keep drinking until no full bottles are available
        while (numBottles > 0) {
            // drink all full bottles
            totalDrunk += numBottles;
            empty += numBottles;
            numBottles = 0;

            // exchange empty bottles if possible
            while (empty >= numExchange) {
                empty -= numExchange;   // use empty bottles
                numBottles += 1;        // get one new bottle
                numExchange++;          // numExchange increases after each exchange
            }
        }

        return totalDrunk;
    }
};
