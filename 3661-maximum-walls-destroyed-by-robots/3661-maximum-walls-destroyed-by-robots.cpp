class Solution {
public:
    typedef pair<int, int> P;
    vector<vector<int>> t;

    int countWalls(vector<int>& walls, int l, int r) {
        int left  = lower_bound(begin(walls), end(walls), l) - begin(walls);
        int right = upper_bound(begin(walls), end(walls), r) - begin(walls);

        return right - left;
    }
    int solve(vector<int>& walls, vector<P>& roboDist, vector<P>& range, int i, int prevDir) {

        if(i == roboDist.size())
            return 0;
        
        if(t[i][prevDir] != -1)
            return t[i][prevDir];

        int leftStart = range[i].first;

        if(prevDir == 1) {
            leftStart = max(leftStart, range[i-1].second + 1);
        }

        int leftTake = countWalls(walls, leftStart, roboDist[i].first) 
                        + solve(walls, roboDist, range, i+1, 0);
                    
        int rightTake = countWalls(walls, roboDist[i].first, range[i].second) 
                        + solve(walls, roboDist, range, i+1, 1);

        
        return t[i][prevDir] = max(leftTake, rightTake);
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();

        vector<P> roboDist(n);
        for (int i = 0; i < n; i++) {
            roboDist[i] = {robots[i], distance[i]};
        }

        sort(begin(roboDist), end(roboDist));
        sort(begin(walls), end(walls));
        vector<P> range(n);

        for(int i = 0; i < n; i++) {
            int pos = roboDist[i].first;
            int d   = roboDist[i].second;

            int leftLimit  = (i == 0)   ? 1   : roboDist[i-1].first+1;
            int rightLimit = (i == n-1) ? 1e9 : roboDist[i+1].first-1;

            int L = max(pos - d, leftLimit);
            int R = min(pos + d, rightLimit);

            range[i] = {L, R};
        }

        t.assign(n+1, vector<int>(2, -1));
        return solve(walls, roboDist, range, 0, 0);
    }
};