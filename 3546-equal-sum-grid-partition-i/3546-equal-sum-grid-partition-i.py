class Solution:
    def canPartitionGrid(self, grid):
        m, n = len(grid), len(grid[0])
        
        total_sum = sum(sum(row) for row in grid)
        
        # If total sum is odd → impossible
        if total_sum % 2 != 0:
            return False
        
        target = total_sum // 2
        
        # ✅ Check horizontal cuts
        curr = 0
        for i in range(m - 1):  # must leave at least one row below
            curr += sum(grid[i])
            if curr == target:
                return True
        
        # ✅ Check vertical cuts
        col_sums = [0] * n
        for j in range(n):
            for i in range(m):
                col_sums[j] += grid[i][j]
        
        curr = 0
        for j in range(n - 1):  # must leave at least one column right
            curr += col_sums[j]
            if curr == target:
                return True
        
        return False