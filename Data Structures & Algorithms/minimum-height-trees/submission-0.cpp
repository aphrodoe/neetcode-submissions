class Solution {
public:
    int bfs(vector<vector<int>>& adj, int node, int n) {
        vector<int> vis(n, 0);
        queue<pair<int, int>> q;
        q.push({node, 0});
        vis[node] = 1;

        int maxh = 0;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int nd = it.first;
            int h = it.second;

            maxh = max(maxh, h);
            for (auto& neigh : adj[nd]) {
                if (!vis[neigh]) {
                    vis[neigh] = 1;
                    q.push({neigh, h + 1});
                }
            }
        }

        return maxh;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> ans;
        int minh = INT_MAX;
        for (int i = 0; i < n; i++) {
            int h = bfs(adj, i, n);
            if (h < minh) {
                minh = h;
                ans.clear();
                ans.push_back(i);
            }
            else if (h == minh) ans.push_back(i);
        }

        return ans;
    }
};