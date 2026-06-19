class Solution {
public:
    bool dfs_cycle(int node, int parent, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for (auto it: adj[node]) {
            if (!vis[it]) {
                if (dfs_cycle(it, node, adj, vis)) return true;
            }
            else if (it != parent) return true;
        }

        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        if (dfs_cycle(0, -1, adj, vis)) return false;

        for (int i = 0; i < n; i++) if (vis[i] == 0) return false;

        return true;
    }
};
