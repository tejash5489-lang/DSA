class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> d = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<p, vector<p>, greater<>> boundrycells; // height,i,j

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // left most and right most col(0,n-1)
        for (int i = 0; i < m; i++) { // row
            for (int j : {0, n - 1}) {
                boundrycells.push({heightMap[i][j], {i, j}});
                visited[i][j] = true;
            }
        }

        // top most and btm most row(0,m-1)
        for (int j = 0; j < n; j++) { // col
            for (int i : {0, m - 1}) {
                boundrycells.push({heightMap[i][j], {i, j}});
                visited[i][j] = true;
            }
        }

        int water = 0;

        while (!boundrycells.empty()) {
            p pp = boundrycells.top();
            boundrycells.pop();

            int height = pp.first;
            int i = pp.second.first;
            int j = pp.second.second;

            // find neigbours
            for (vector<int>& dir : d) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n &&
                    !visited[i_][j_]) {
                    water += max(height - heightMap[i_][j_], 0);
                    boundrycells.push(
                        {max(height, heightMap[i_][j_]), {i_, j_}});
                    visited[i_][j_] = true;
                }
            }
        }
        return water;
    }
};