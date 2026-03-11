class Solution(object):
    def bitwiseComplement(self, n):
        if n == 0:
            return 1
        
        bits = n.bit_length()
        mask = (1 << bits) - 1
        return n ^ mask