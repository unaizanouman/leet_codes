class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st; // acts as a stack
        for (int num : nums) {
            st.push_back(num);
            // Keep merging as long as top two are non-coprime
            while (st.size() > 1) {
                int a = st[st.size()-2], b = st.back();
                int g = gcd(a, b);
                if (g == 1) break;  // coprime → stop merging
                long long lcm = (1LL * a * b) / g; // calculate LCM safely
                st.pop_back();
                st.back() = lcm; // replace with LCM
            }
        }
        return st;
    }
};
