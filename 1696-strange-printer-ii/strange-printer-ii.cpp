class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int m = targetGrid.size();
        int n = targetGrid[0].size();

        // Bounding rectangle of each color
        vector<int> top(61, INT_MAX);
        vector<int> left(61, INT_MAX);
        vector<int> bottom(61, -1);
        vector<int> right(61, -1);

        // Step 1: Find bounding rectangles
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int c = targetGrid[i][j];

                top[c] = min(top[c], i);
                bottom[c] = max(bottom[c], i);

                left[c] = min(left[c], j);
                right[c] = max(right[c], j);
            }
        }

        // Step 2: Build graph
        vector<vector<int>> graph(61);
        vector<int> indegree(61, 0);

        for (int c = 1; c <= 60; c++) {

            // Color doesn't exist
            if (bottom[c] == -1)
                continue;

            unordered_set<int> seen;

            // Traverse bounding rectangle
            for (int i = top[c]; i <= bottom[c]; i++) {
                for (int j = left[c]; j <= right[c]; j++) {

                    int other = targetGrid[i][j];

                    if (other != c && !seen.count(other)) {

                        graph[c].push_back(other);
                        indegree[other]++;

                        seen.insert(other);
                    }
                }
            }
        }

        // Step 3: Kahn's Algorithm
        queue<int> q;
        int totalColors = 0;

        for (int c = 1; c <= 60; c++) {

            if (bottom[c] != -1) {

                totalColors++;

                if (indegree[c] == 0)
                    q.push(c);
            }
        }

        // Step 4: BFS
        int processed = 0;

        while (!q.empty()) {

            int u = q.front();
            q.pop();

            processed++;

            for (int v : graph[u]) {

                indegree[v]--;

                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        // Step 5: Check for cycle
        return processed == totalColors;
    }
};