class Solution {

    int[] parent, size;

    int find(int x){
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void union(int a, int b){
        a = find(a);
        b = find(b);
        if(a != b){
            if(size[a] < size[b]){
                int t = a; a = b; b = t;
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }

    public int latestDayToCross(int row, int col, int[][] cells) {
        int n = row * col;
        int TOP = n, BOTTOM = n + 1;

        parent = new int[n + 2];
        size = new int[n + 2];

        for(int i = 0; i <= n + 1; i++){
            parent[i] = i;
            size[i] = 1;
        }

        int[][] grid = new int[row][col];
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                grid[i][j] = 1; // water

        int[][] dir = {{1,0},{-1,0},{0,1},{0,-1}};

        for(int i = cells.length - 1; i >= 0; i--){
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 0; // land
            int id = r * col + c;

            if(r == 0) union(id, TOP);
            if(r == row - 1) union(id, BOTTOM);

            for(int[] d : dir){
                int nr = r + d[0], nc = c + d[1];
                if(nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 0){
                    union(id, nr * col + nc);
                }
            }

            if(find(TOP) == find(BOTTOM))
                return i;
        }
        return 0;
    }
}
