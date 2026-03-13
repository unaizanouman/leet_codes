class Solution(object):
    def minNumberOfSeconds(self, mountainHeight, workerTimes):
        import math
        
        def can_finish(T):
            total = 0
            for t in workerTimes:
                val = (2 * T) // t
                x = int((math.sqrt(1 + 4 * val) - 1) // 2)
                total += x
                if total >= mountainHeight:
                    return True
            return False
        
        left, right = 0, 10**18
        
        while left < right:
            mid = (left + right) // 2
            if can_finish(mid):
                right = mid
            else:
                left = mid + 1
        
        return left
