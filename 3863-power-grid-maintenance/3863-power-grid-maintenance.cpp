#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rank;
    DSU(int n) : parent(n+1), rank(n+1, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);
        for (auto &e : connections)
            dsu.unite(e[0], e[1]);

        unordered_map<int, set<int>> comp;
        for (int i = 1; i <= c; ++i)
            comp[dsu.find(i)].insert(i);

        vector<bool> online(c+1, true);
        vector<int> ans;

        for (auto &q : queries) {
            int type = q[0], x = q[1];
            int root = dsu.find(x);
            if (type == 1) {
                if (online[x]) ans.push_back(x);
                else if (!comp[root].empty()) ans.push_back(*comp[root].begin());
                else ans.push_back(-1);
            } else { // type == 2
                if (online[x]) {
                    online[x] = false;
                    comp[root].erase(x);
                }
            }
        }
        return ans;
    }
};
