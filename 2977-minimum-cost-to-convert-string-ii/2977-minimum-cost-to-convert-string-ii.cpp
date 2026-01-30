class Solution {
public:
    struct TrieNode {
        TrieNode* next[26];
        int id;
        TrieNode() {
            memset(next, 0, sizeof(next));
            id = -1;
        }
    };

    void insert(TrieNode* root, const string& s, int id) {
        TrieNode* node = root;
        for (char c : s) {
            int idx = c - 'a';
            if (!node->next[idx]) node->next[idx] = new TrieNode();
            node = node->next[idx];
        }
        node->id = id;
    }

    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {
        int n = source.size();
        unordered_map<string, int> mp;
        TrieNode* root = new TrieNode();
        int idCounter = 0;

        for (auto& s : original) {
            if (!mp.count(s)) {
                mp[s] = idCounter;
                insert(root, s, idCounter++);
            }
        }
        for (auto& s : changed) {
            if (!mp.count(s)) {
                mp[s] = idCounter;
                insert(root, s, idCounter++);
            }
        }

        const long long INF = LLONG_MAX / 4;
        vector<vector<long long>> dist(idCounter, vector<long long>(idCounter, INF));
        for (int i = 0; i < idCounter; i++) dist[i][i] = 0;

        for (int i = 0; i < original.size(); i++) {
            int u = mp[original[i]];
            int v = mp[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < idCounter; k++) {
            for (int i = 0; i < idCounter; i++) {
                if (dist[i][k] == INF) continue;
                for (int j = 0; j < idCounter; j++) {
                    if (dist[k][j] == INF) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == INF) continue;

            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            TrieNode* tNode = root;
            unordered_map<int, int> lenToTarget;

            for (int j = i; j < n; j++) {
                int idx = target[j] - 'a';
                if (!tNode->next[idx]) break;
                tNode = tNode->next[idx];
                if (tNode->id != -1) {
                    lenToTarget[j - i + 1] = tNode->id;
                }
            }

            TrieNode* sNode = root;
            for (int j = i; j < n; j++) {
                int idx = source[j] - 'a';
                if (!sNode->next[idx]) break;
                sNode = sNode->next[idx];
                if (sNode->id != -1) {
                    int len = j - i + 1;
                    if (lenToTarget.count(len)) {
                        int sId = sNode->id;
                        int tId = lenToTarget[len];
                        if (dist[sId][tId] != INF) {
                            dp[i + len] = min(dp[i + len], dp[i] + dist[sId][tId]);
                        }
                    }
                }
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};