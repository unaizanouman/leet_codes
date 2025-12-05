class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        long long maxArea = 0;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int right = i;
                int left = st.empty() ? -1 : st.top();
                long long width = right - left - 1;
                maxArea = max(maxArea, width * h);
            }
            st.push(i);
        }
        return maxArea;
    }
};
