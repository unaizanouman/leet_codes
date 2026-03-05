class Solution(object):
    def minOperations(self, s):
        change_start0 = 0
        change_start1 = 0
        
        for i in range(len(s)):
            # pattern starting with 0 -> 010101
            expected0 = '0' if i % 2 == 0 else '1'
            
            # pattern starting with 1 -> 101010
            expected1 = '1' if i % 2 == 0 else '0'
            
            if s[i] != expected0:
                change_start0 += 1
                
            if s[i] != expected1:
                change_start1 += 1
        
        return min(change_start0, change_start1)