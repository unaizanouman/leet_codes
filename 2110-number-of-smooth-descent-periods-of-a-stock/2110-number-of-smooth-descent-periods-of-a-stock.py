class Solution:
    def getDescentPeriods(self, prices):
        ans = 1
        count = 1

        for i in range(1, len(prices)):
            if prices[i - 1] - prices[i] == 1:
                count += 1
            else:
                count = 1
            ans += count

        return ans
