import heapq

class Solution:
    def maxTwoEvents(self, events):
        events.sort(key=lambda x: x[0])
        heap = [] 
        max_val = 0
        ans = 0
        for start, end, value in events:
            while heap and heap[0][0] < start:
                _, v = heapq.heappop(heap)
                max_val = max(max_val, v)
            ans = max(ans, max_val + value)
            heapq.heappush(heap, (end, value))
        return ans