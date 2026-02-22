class Solution(object):
    def binaryGap(self, n):
        bits = bin(n)
        last = bits.find('1')
        max_dist = 0
        
        for i in range(last + 1, len(bits)):
            if bits[i] == '1':
                max_dist = max(max_dist, i - last)
                last = i
        
        return max_dist