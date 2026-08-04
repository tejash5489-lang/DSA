class Solution {
public:
    int m, n;
    void dfs(vector<vector<int>>& grid, int r, int c, int color) {
        if (r < 0 || c >= n   || r >= m  || c < 0 || grid[r][c] != color)
            return;

        grid[r][c] = INT_MAX;

        dfs(grid, r + 1, c, color);
        dfs(grid, r, c + 1, color);
        dfs(grid, r - 1, c, color);
        dfs(grid, r, c - 1, color);
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col,
                                    int color) {
        vector<vector<int>> temp(grid);
        m = grid.size();
        n = grid[0].size();

        dfs(temp, row, col, grid[row][col]);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {

                    if (temp[i][j] == INT_MAX) {
                        grid[i][j] = color;
                    }
                }

                else {
                    if (temp[i][j]==INT_MAX && (temp[i - 1][j] != INT_MAX ||
                                       temp[i + 1][j] != INT_MAX ||
                                       temp[i][j - 1] != INT_MAX ||
                                       temp[i][j + 1] != INT_MAX)) {
                        grid[i][j] = color;
                    }
                }
            }
        }
    return grid;
    }
};