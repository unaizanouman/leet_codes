class Solution(object):
    def minFlips(self, s):
        n = len(s)
        s2 = s + s
        
        alt1 = ""
        alt2 = ""
        
        for i in range(2*n):
            alt1 += "0" if i % 2 == 0 else "1"
            alt2 += "1" if i % 2 == 0 else "0"
        
        res = float('inf')
        diff1 = diff2 = 0
        left = 0
        
        for right in range(2*n):
            
            if s2[right] != alt1[right]:
                diff1 += 1
            if s2[right] != alt2[right]:
                diff2 += 1
            
            if right - left + 1 > n:
                if s2[left] != alt1[left]:
                    diff1 -= 1
                if s2[left] != alt2[left]:
                    diff2 -= 1
                left += 1
            
            if right - left + 1 == n:
                res = min(res, diff1, diff2)
        
        return res