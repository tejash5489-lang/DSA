class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<int> prev(m, 0);
        vector<int> curr(m, 0);

        // First row
        prev[0] = grid[0][0];

        for (int j = 1; j < m; j++) {
            prev[j] = grid[0][j] + prev[j - 1];
        }

        // Remaining rows
        for (int i = 1; i < n; i++) {

            curr[0] = grid[i][0] + prev[0];

            for (int j = 1; j < m; j++) {

                curr[j] = grid[i][j] + min(prev[j], curr[j - 1]);
            }

            prev = curr;
        }

        return prev[m - 1];
    }
};