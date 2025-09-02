class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            int xA = points[i][0], yA = points[i][1];
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                int xB = points[j][0], yB = points[j][1];

                // A is on the upper-left side of B (allow lines)
                if (xA <= xB && yA >= yB && (xA < xB || yA > yB)) {
                    bool empty = true;
                    for (int k = 0; k < n; ++k) {
                        if (k == i || k == j) continue;
                        int x = points[k][0], y = points[k][1];
                        // any point inside or on the border invalidates
                        if (xA <= x && x <= xB && yB <= y && y <= yA) {
                            empty = false;
                            break;
                        }
                    }
                    if (empty) ++ans;
                }
            }
        }
        return ans;
    }
};
