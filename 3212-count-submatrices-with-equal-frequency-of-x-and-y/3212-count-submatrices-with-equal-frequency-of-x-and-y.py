class Solution:
    def numberOfSubmatrices(self, grid):
        m, n = len(grid), len(grid[0])
        
        # prefix sum for (X=+1, Y=-1, .=0)
        prefix = [[0]*n for _ in range(m)]
        
        # prefix count for number of X
        x_count = [[0]*n for _ in range(m)]
        
        def value(c):
            if c == 'X':
                return 1
            elif c == 'Y':
                return -1
            return 0
        
        for i in range(m):
            for j in range(n):
                val = value(grid[i][j])
                
                prefix[i][j] = val
                x_count[i][j] = 1 if grid[i][j] == 'X' else 0
                
                if i > 0:
                    prefix[i][j] += prefix[i-1][j]
                    x_count[i][j] += x_count[i-1][j]
                if j > 0:
                    prefix[i][j] += prefix[i][j-1]
                    x_count[i][j] += x_count[i][j-1]
                if i > 0 and j > 0:
                    prefix[i][j] -= prefix[i-1][j-1]
                    x_count[i][j] -= x_count[i-1][j-1]
        
        count = 0
        
        for i in range(m):
            for j in range(n):
                if prefix[i][j] == 0 and x_count[i][j] > 0:
                    count += 1
        
        return count