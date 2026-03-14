class Solution(object):
    def getHappyString(self, n, k):
        result = []

        def backtrack(s):
            if len(result) >= k:
                return
            
            if len(s) == n:
                result.append(s)
                return
            
            for ch in ['a','b','c']:
                if not s or s[-1] != ch:
                    backtrack(s + ch)

        backtrack("")
        
        return result[k-1] if k <= len(result) else ""