class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        vector<bool> sus(n, false);

        for (auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        // BFS

        queue<int> q;
        q.push(k);
        sus[k] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int& nghr : adj[curr]) {
                indegree[nghr]--;
                if (!sus[nghr]) {
                    q.push(nghr);
                    sus[nghr] = true;
                }
            }
        }

            vector<int> ans;
            bool cantremove = false;
            for (int i = 0; i < n; i++) {
                if (sus[i] && indegree[i] > 0) {
                    cantremove = true;
                    break;
                }
                if (!sus[i]) {
                    ans.push_back(i);
                }
            }

            if (cantremove) {
                vector<int> vec(n);
                for (int i = 0; i < n; i++) {
                    vec[i] = i;
                }
                return vec;
            }
        return ans;
    }
};