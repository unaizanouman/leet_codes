class Solution:
    def largestMagicSquare(self, grid):
        m = len(grid)
        n = len(grid[0])

        # Prefix sums
        rowSum = [[0] * (n + 1) for _ in range(m)]
        colSum = [[0] * n for _ in range(m + 1)]

        for i in range(m):
            for j in range(n):
                rowSum[i][j + 1] = rowSum[i][j] + grid[i][j]
                colSum[i + 1][j] = colSum[i][j] + grid[i][j]

        def isMagic(r, c, k):
            target = rowSum[r][c + k] - rowSum[r][c]

            # check rows
            for i in range(r, r + k):
                if rowSum[i][c + k] - rowSum[i][c] != target:
                    return False

            # check columns
            for j in range(c, c + k):
                if colSum[r + k][j] - colSum[r][j] != target:
                    return False

            # check diagonals
            diag1 = 0
            diag2 = 0
            for i in range(k):
                diag1 += grid[r + i][c + i]
                diag2 += grid[r + i][c + k - 1 - i]

            return diag1 == target and diag2 == target

        ans = 1
        for k in range(2, min(m, n) + 1):
            for i in range(m - k + 1):
                for j in range(n - k + 1):
                    if isMagic(i, j, k):
                        ans = k

        return ans