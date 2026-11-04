class Solution {
public:
    vector<int> rank;
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_ = find(x);
        int y_ = find(y);

        if (x_ == y_)
            return;

        if (rank[x_] < rank[y_])
            parent[y_] = x_;

        else if (rank[y_] < rank[x_])
            parent[x_] = y_;

        else {
            parent[x_] = y_;
            rank[y_]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        rank.resize(n + 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        for (auto& ed : edges) {
            int u = ed[0];
            int v = ed[1];

            if (find(u) == find(v))
                return ed;

            Union(u, v);
        }
        return {};
    }
};