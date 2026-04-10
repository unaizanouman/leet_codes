class Solution:
    def minimumDistance(self, nums):
        from collections import defaultdict
        
        positions = defaultdict(list)
        for i, num in enumerate(nums):
            positions[num].append(i)
        
        ans = float('inf')
        for val in positions:
            idxs = positions[val]
            
            if len(idxs) < 3:
                continue
            for i in range(len(idxs) - 2):
                left = idxs[i]
                right = idxs[i + 2]
                
                ans = min(ans, 2 * (right - left))
        
        return ans if ans != float('inf') else -1