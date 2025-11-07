#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canAchieve(long long target, vector<long long>& power, int r, long long k) {
        int n = power.size();
        vector<long long> diff(n + 1, 0);
        long long used = 0, currAdd = 0;

        for (int i = 0; i < n; ++i) {
            currAdd += diff[i];
            long long total = power[i] + currAdd;
            if (total < target) {
                long long need = target - total;
                used += need;
                if (used > k) return false;
                currAdd += need;
                if (i + 2 * r + 1 < n)
                    diff[i + 2 * r + 1] -= need;
            }
        }
        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> prefix(n + 1, 0), power(n, 0);

        // Prefix sum to compute initial power per city
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + stations[i];

        for (int i = 0; i < n; ++i) {
            int left = max(0, i - r);
            int right = min(n, i + r + 1);
            power[i] = prefix[right] - prefix[left];
        }

        long long low = 0, high = *max_element(power.begin(), power.end()) + k;
        long long ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;
            if (canAchieve(mid, power, r, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
