class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> indegree(numCourses, 0);
        for (auto it : adj) {
            for (auto n : it) indegree[n]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            topo.push_back(n);
            for (auto it : adj[n]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        return (topo.size() == numCourses);
    }
};
