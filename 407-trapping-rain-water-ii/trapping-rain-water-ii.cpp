class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();    // row
        int m = heightMap[0].size(); // col

        priority_queue<p, vector<p>, greater<>> bc;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // topmost and btmmost
        for (int j = 0; j < m; j++) { // col
            for (int i : {0, n - 1}) {
                bc.push({heightMap[i][j], {i, j}});
                vis[i][j] = true;
            }
        }

        // leftmost and rightmost
        for (int i = 0; i < n; i++) { // row
            for (int j : {0, m - 1}) {
                bc.push({heightMap[i][j], {i, j}});
                vis[i][j] = true;
            }
        }

        int water = 0;

        while (!bc.empty()) {
            p pp = bc.top();
            bc.pop();

            int height = pp.first;
            int i = pp.second.first;
            int j = pp.second.second;

            for (auto& d : dir) {
                int i_ = i + d[0];
                int j_ = j + d[1];

                if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && !vis[i_][j_]) {
                    water += max(height - heightMap[i_][j_], 0);
                    bc.push({max(height, heightMap[i_][j_]), {i_, j_}});
                    vis[i_][j_] = true;
                }
            }
        }
        return water;
    }
};