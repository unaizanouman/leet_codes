class Solution:
    def minAbsDiff(self, grid, k):
        m, n = len(grid), len(grid[0])
        
        result = []
        
        for i in range(m - k + 1):
            row = []
            for j in range(n - k + 1):
                
                # Step 1: collect elements
                values = []
                for x in range(i, i + k):
                    for y in range(j, j + k):
                        values.append(grid[x][y])
                
                # Step 2: remove duplicates
                values = list(set(values))
                
                # Step 3: if only 1 value → answer = 0
                if len(values) <= 1:
                    row.append(0)
                    continue
                
                # Step 4: sort
                values.sort()
                
                # Step 5: find minimum difference
                min_diff = float('inf')
                for t in range(1, len(values)):
                    min_diff = min(min_diff, values[t] - values[t-1])
                
                row.append(min_diff)
            
            result.append(row)
        
        return result