class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result;
        int prefix = 0;

        for (int bit : nums) {
            prefix = (prefix * 2 + bit) % 5;
            result.push_back(prefix == 0);
        }

        return result;
    }
};
