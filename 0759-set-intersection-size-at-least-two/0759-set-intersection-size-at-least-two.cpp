class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            if (a[1] != b[1]) return a[1] < b[1]; 
            return a[0] > b[0];
        });

        vector<int> nums;
        
        for (auto &iv : intervals) {
            int start = iv[0], end = iv[1];
            int cnt = 0;
            for (int i = nums.size() - 1; i >= 0 && nums[i] >= start; --i) {
                if (nums[i] <= end) cnt++;
                if (cnt == 2) break;
            }
            
            if (cnt == 2) continue;
            
            if (cnt == 1) {
                nums.push_back(end);
            } else {
                nums.push_back(end - 1);
                nums.push_back(end);
            }
        }

        return nums.size();
    }
};
