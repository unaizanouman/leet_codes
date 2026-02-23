class Solution(object):
    def hasAllCodes(self, s, k):
        n = len(s)
        
        if n < k:
            return False
        
        total = 1 << k  # 2^k
        seen = set()
        mask = 0
        
        for i in range(n):
            # keep last k bits only
            mask = ((mask << 1) & (total - 1)) | (ord(s[i]) - ord('0'))
            
            if i >= k - 1:
                seen.add(mask)
                if len(seen) == total:
                    return True
        return False