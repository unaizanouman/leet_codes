class Solution:
    def countCoveredBuildings(self, n, buildings):
        from collections import defaultdict
        
        row_min = defaultdict(lambda: float('inf'))
        row_max = defaultdict(lambda: float('-inf'))
        col_min = defaultdict(lambda: float('inf'))
        col_max = defaultdict(lambda: float('-inf'))
        
        for x, y in buildings:
            row_min[x] = min(row_min[x], y)
            row_max[x] = max(row_max[x], y)
            col_min[y] = min(col_min[y], x)
            col_max[y] = max(col_max[y], x)
        
        covered = 0
        
        for x, y in buildings:
            if (row_min[x] < y and row_max[x] > y and 
                col_min[y] < x and col_max[y] > x):
                covered += 1
        
        return covered
