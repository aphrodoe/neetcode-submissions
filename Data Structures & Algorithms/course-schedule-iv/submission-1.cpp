class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<unordered_set<int>> adj(numCourses), pre(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]].insert(prerequisites[i][1]);
        }

        vector<int> indegree(numCourses, 0);
        for (auto& it : adj) {
            for (auto& node : it) indegree[node]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto& it : adj[node]) {
                indegree[it]--;
                pre[it].insert(node);
                pre[it].insert(pre[node].begin(), pre[node].end());
                if (indegree[it] == 0) q.push(it);
            }
        }

        vector<bool> ans;
        for (int i = 0; i < queries.size(); i++) {
            if (pre[queries[i][1]].count(queries[i][0]) == 0) ans.push_back(false);
            else ans.push_back(true);
        }

        return ans;
    }
};