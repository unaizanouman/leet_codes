import heapq

class Solution:
    def maxTwoEvents(self, events):
        # Sort events by start time
        events.sort(key=lambda x: x[0])

        heap = []  # (endTime, value)
        max_val = 0
        ans = 0

        for start, end, value in events:
            # Remove all events that end before this starts
            while heap and heap[0][0] < start:
                _, v = heapq.heappop(heap)
                max_val = max(max_val, v)

            # Combine current event with best previous non-overlapping event
            ans = max(ans, max_val + value)

            # Push current event
            heapq.heappush(heap, (end, value))

        return ans
