class Solution(object):
    def numSteps(self, s):
        steps = 0
        carry = 0
        
        # Traverse from right to left (skip MSB)
        for i in range(len(s) - 1, 0, -1):
            bit = int(s[i])
            
            if bit + carry == 1:
                # odd → add 1 then divide
                steps += 2
                carry = 1
            else:
                # even → just divide
                steps += 1
        
        # If carry remains at MSB
        return steps + carry