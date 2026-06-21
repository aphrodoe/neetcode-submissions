class Solution {
public:
    void dfs(string node, unordered_map<string, vector<string>>& adj, vector<string>& ans) {
        while (!adj[node].empty()) {
            string dst = adj[node].back();
            adj[node].pop_back();
            dfs(dst, adj, ans);
        }
        ans.push_back(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        for (auto& it : tickets) adj[it[0]].push_back(it[1]);
        for (auto& it : adj) sort(it.second.rbegin(), it.second.rend());
        vector<string> ans;

        dfs("JFK", adj, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
