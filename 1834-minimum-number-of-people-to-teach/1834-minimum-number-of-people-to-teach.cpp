class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        
        // Convert each user's known languages into a set
        vector<unordered_set<int>> lang_sets(m);
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                lang_sets[i].insert(lang);
            }
        }

        // Step 1: Find problematic users (friendships with no common language)
        unordered_set<int> problematic_users;
        for (auto& f : friendships) {
            int u = f[0] - 1, v = f[1] - 1;
            bool canCommunicate = false;
            for (int lang : lang_sets[u]) {
                if (lang_sets[v].count(lang)) {
                    canCommunicate = true;
                    break;
                }
            }
            if (!canCommunicate) {
                problematic_users.insert(u);
                problematic_users.insert(v);
            }
        }

        if (problematic_users.empty()) return 0;

        // Step 2: Count how many problematic users already know each language
        vector<int> count(n + 1, 0);
        for (int user : problematic_users) {
            for (int lang : lang_sets[user]) {
                count[lang]++;
            }
        }

        // Step 3: Find the language with the maximum overlap
        int max_known = *max_element(count.begin(), count.end());

        // Step 4: Answer = total problematic users - those who already know that best language
        return problematic_users.size() - max_known;
    }
};
