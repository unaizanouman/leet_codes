class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i <= n - k; i++) {
            unordered_map<int, int> freq;
            for (int j = i; j < i + k; j++)
                freq[nums[j]]++;

            vector<pair<int, int>> v(freq.begin(), freq.end());
            sort(v.begin(), v.end(), [](auto& a, auto& b) {
                if (a.second == b.second)
                    return a.first > b.first;
                return a.second > b.second;
            });
            int cnt = 0;
            int sum = 0;
            for (auto& [num, f] : v) {
                if (cnt == x) break;
                sum += num * f;
                cnt++;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
