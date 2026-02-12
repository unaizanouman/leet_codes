class Solution(object):
    def longestBalanced(self, s):
        n = len(s)
        ans = 0
        for i in range(n):
            freq = [0] * 26

            for j in range(i, n):
                index = ord(s[j]) - ord('a')
                freq[index] += 1
                max_freq = 0
                min_freq = float('inf')
                for f in freq:
                    if f > 0:
                        max_freq = max(max_freq, f)
                        min_freq = min(min_freq, f)
                if max_freq == min_freq:
                    ans = max(ans, j - i + 1)
        return ans