class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        // precompute powers of 4: 4^0, 4^1, 4^2, ...
        const long long LIM = (long long)1e18; // safe upper bound
        vector<long long> pow4;
        pow4.push_back(1);
        while (pow4.back() <= LIM / 4) pow4.push_back(pow4.back() * 4);

        long long answer = 0;
        for (auto &q : queries) {
            long long l = q[0], r = q[1];
            long long sumCosts = 0;

            // costs k correspond to x in [4^(k-1), 4^k - 1], for k >= 1
            for (int k = 1; k < (int)pow4.size(); ++k) {
                long long low = pow4[k-1];
                long long high = pow4[k] - 1;
                if (low > r) break; // no more overlap possible
                long long L = max(l, low);
                long long R = min(r, high);
                if (L <= R) {
                    sumCosts += (R - L + 1) * 1LL * k;
                }
            }

            // each operation applies to two elements -> ceil(sumCosts / 2)
            answer += (sumCosts + 1) / 2;
        }
        return answer;
    }
};
