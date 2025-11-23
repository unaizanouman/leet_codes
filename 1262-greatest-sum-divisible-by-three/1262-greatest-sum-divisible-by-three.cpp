class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int total = 0;
        vector<int> r1, r2;

        for (int x : nums) {
            total += x;
            if (x % 3 == 1) r1.push_back(x);
            else if (x % 3 == 2) r2.push_back(x);
        }

        sort(r1.begin(), r1.end());
        sort(r2.begin(), r2.end());

        if (total % 3 == 0) return total;

        int ans = 0;

        if (total % 3 == 1) {
            int op1 = r1.size() ? total - r1[0] : -1;
            int op2 = r2.size() > 1 ? total - r2[0] - r2[1] : -1;
            ans = max(op1, op2);
        } else { // total % 3 == 2
            int op1 = r2.size() ? total - r2[0] : -1;
            int op2 = r1.size() > 1 ? total - r1[0] - r1[1] : -1;
            ans = max(op1, op2);
        }

        return ans < 0 ? 0 : ans;
    }
};
