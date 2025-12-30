/**
 * @param {number[][]} grid
 * @return {number}
 */
var numMagicSquaresInside = function(grid) {
    const rows = grid.length;
    const cols = grid[0].length;
    let count = 0;

    function isMagic(r, c) {
        // Center must be 5
        if (grid[r+1][c+1] !== 5) return false;

        let seen = new Set();

        // Check numbers 1..9 and uniqueness
        for (let i = r; i < r + 3; i++) {
            for (let j = c; j < c + 3; j++) {
                let val = grid[i][j];
                if (val < 1 || val > 9 || seen.has(val)) return false;
                seen.add(val);
            }
        }

        // Check rows
        for (let i = 0; i < 3; i++) {
            if (
                grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] !== 15 ||
                grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i] !== 15
            ) return false;
        }

        // Check diagonals
        if (
            grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] !== 15 ||
            grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] !== 15
        ) return false;

        return true;
    }

    for (let i = 0; i <= rows - 3; i++) {
        for (let j = 0; j <= cols - 3; j++) {
            if (isMagic(i, j)) count++;
        }
    }

    return count;
};
