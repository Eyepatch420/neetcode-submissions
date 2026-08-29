class Solution {
   public:
    void dfs(int r, int c, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        grid[r][c] = '0';
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1') {
                dfs(nr, nc, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int island = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c] == '1') {
                    island++;
                    dfs(r, c, grid);
                }
            }
        }
        return island;
    }
};
