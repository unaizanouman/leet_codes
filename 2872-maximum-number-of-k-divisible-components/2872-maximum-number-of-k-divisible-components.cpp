class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int result = 0;
        function<long long(int,int)> dfs = [&](int node, int parent) {
            long long sum = values[node];
            for (int nxt : g[node]) {
                if (nxt == parent) continue;
                sum += dfs(nxt, node);
            }
            if (sum % k == 0) {
                result++;  
                return 0LL; 
            }
            return sum;  
        };

        dfs(0, -1);
        return result;
    }
};
