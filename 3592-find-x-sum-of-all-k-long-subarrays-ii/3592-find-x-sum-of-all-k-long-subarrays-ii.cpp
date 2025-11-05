#include <bits/stdc++.h>
using namespace std;

struct Node {
    int freq;
    long long val;
    bool operator<(const Node &other) const {
        if (freq == other.freq) return val < other.val;
        return freq < other.freq;
    }
};

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<long long, int> freq;
        multiset<Node> top, rest;
        long long topSum = 0;
        vector<long long> ans;

        auto balance = [&]() {
            while ((int)top.size() > x) {
                auto it = top.begin();
                topSum -= it->freq * it->val;
                rest.insert(*it);
                top.erase(it);
            }
            while ((int)top.size() < x && !rest.empty()) {
                auto it = prev(rest.end());
                topSum += it->freq * it->val;
                top.insert(*it);
                rest.erase(it);
            }
            if (!top.empty() && !rest.empty()) {
                while (true) {
                    auto tIt = top.begin();
                    auto rIt = prev(rest.end());
                    if (tIt->freq < rIt->freq || (tIt->freq == rIt->freq && tIt->val < rIt->val)) {
                        topSum -= tIt->freq * tIt->val;
                        topSum += rIt->freq * rIt->val;
                        rest.insert(*tIt);
                        top.insert(*rIt);
                        rest.erase(rIt);
                        top.erase(tIt);
                    } else break;
                }
            }
        };

        auto add = [&](long long val) {
            int old = freq[val]++;
            Node nodeOld = {old, val};
            Node nodeNew = {old + 1, val};
            if (old > 0) {
                if (top.count(nodeOld)) {
                    top.erase(top.find(nodeOld));
                    topSum -= nodeOld.freq * nodeOld.val;
                } else rest.erase(rest.find(nodeOld));
            }
            top.insert(nodeNew);
            topSum += nodeNew.freq * nodeNew.val;
            balance();
        };

        auto remove = [&](long long val) {
            int old = freq[val]--;
            Node nodeOld = {old, val};
            Node nodeNew = {old - 1, val};
            if (top.count(nodeOld)) {
                top.erase(top.find(nodeOld));
                topSum -= nodeOld.freq * nodeOld.val;
            } else rest.erase(rest.find(nodeOld));

            if (nodeNew.freq > 0) {
                rest.insert(nodeNew);
            } else freq.erase(val);
            balance();
        };

        for (int i = 0; i < k; ++i) add(nums[i]);
        ans.push_back(topSum);
        for (int i = k; i < n; ++i) {
            remove(nums[i - k]);
            add(nums[i]);
            ans.push_back(topSum);
        }
        return ans;
    }
};
