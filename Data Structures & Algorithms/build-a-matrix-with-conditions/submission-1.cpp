class Solution {
public:
    vector<int> topo(vector<vector<int>>& adj, int k) {
        vector<int> indegree(k + 1, 0);
        for (auto& it : adj) {
            for (auto& n : it) indegree[n]++;
        }

        vector<int> ans;
        queue<int> q;
        for (int i = 1; i <= k; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int n = q.front();
            q.pop();
            ans.push_back(n);
            for (auto& it : adj[n]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        return ans;
    };

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> adjr(k + 1), adjc(k + 1);
        for (int i = 0; i < rowConditions.size(); i++) {
            adjr[rowConditions[i][0]].push_back(rowConditions[i][1]);
        }
        for (int i = 0; i < colConditions.size(); i++) {
            adjc[colConditions[i][0]].push_back(colConditions[i][1]);
        }

        vector<int> trow = topo(adjr, k);
        vector<int> tcol = topo(adjc, k);

        vector<vector<int>> ans;
        if (trow.size() != k || tcol.size() != k) return ans;

        ans.resize(k, vector<int>(k, 0));
        unordered_map<int, int> row, col;
        for (int i = 0; i < k; i++) {
            row[trow[i]] = i;
            col[tcol[i]] = i;
        }
        
        for (int i = 1; i <= k; i++) {
            ans[row[i]][col[i]] = i;
        }

        return ans;
    }
};