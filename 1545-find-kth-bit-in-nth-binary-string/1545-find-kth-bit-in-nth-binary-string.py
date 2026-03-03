class Solution(object):
    def findKthBit(self, n, k):
        if n == 1:
            return "0"
        mid = 1 << (n - 1)  # 2^(n-1)
        
        if k == mid:
            return "1"
        elif k < mid:
            return self.findKthBit(n - 1, k)
        else:
            bit = self.findKthBit(n - 1, (1 << n) - k)
            return "1" if bit == "0" else "0"