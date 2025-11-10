class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> st;
        int ans = 0;
        for (int v : nums) {
            while (!st.empty() && st.back() > v) {
                st.pop_back();
                ++ans;
            }
            if (v > 0) {
                if (st.empty() || st.back() < v) st.push_back(v);
            }
        }
        while (!st.empty()) {
            if (st.back() > 0) ++ans;
            st.pop_back();
        }
        return ans;
    }
};
