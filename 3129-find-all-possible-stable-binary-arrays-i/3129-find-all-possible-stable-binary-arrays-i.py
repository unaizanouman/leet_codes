class Solution(object):
    def numberOfStableArrays(self, zero, one, limit):
        MOD = 10**9 + 7
        
        dp0 = [[0]*(one+1) for _ in range(zero+1)]
        dp1 = [[0]*(one+1) for _ in range(zero+1)]
        
        # base: starting blocks
        for z in range(1, min(limit, zero) + 1):
            dp0[z][0] = 1
        for o in range(1, min(limit, one) + 1):
            dp1[0][o] = 1
        
        for z in range(zero+1):
            for o in range(one+1):
                if z==0 and o==0:
                    continue
                
                # end with 0
                for k in range(1, min(limit, z) + 1):
                    dp0[z][o] = (dp0[z][o] + dp1[z-k][o]) % MOD
                
                # end with 1
                for k in range(1, min(limit, o) + 1):
                    dp1[z][o] = (dp1[z][o] + dp0[z][o-k]) % MOD
        
        return (dp0[zero][one] + dp1[zero][one]) % MOD