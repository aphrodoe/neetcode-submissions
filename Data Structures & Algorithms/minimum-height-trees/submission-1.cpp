class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> degree(n);
        queue<int> leaves;
        for (int i = 0; i < n; i++) {
            degree[i] = adj[i].size();
            if (degree[i] == 1) leaves.push(i);
        }

        while (!leaves.empty()) {
            if (n <= 2) {
                vector<int> ans;
                while (!leaves.empty()) {
                    ans.push_back(leaves.front());
                    leaves.pop();
                }
                return ans;
            }
            int sz = leaves.size();
            for (int i = 0; i < sz; i++) {
                int node = leaves.front();
                leaves.pop();
                n--;
                for (int& neigh : adj[node]) {
                    degree[neigh]--;
                    if (degree[neigh] == 1) leaves.push(neigh);
                }
            }
        }

        return {};
    }
};