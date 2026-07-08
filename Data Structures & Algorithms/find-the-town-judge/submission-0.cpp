class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<unordered_set<int>> adj(n + 1);
        for (int i = 0; i < trust.size(); i++) {
            adj[trust[i][0]].insert(trust[i][1]);
        }

        vector<int> candidates;
        for (int i = 1; i <= n; i++) {
            if (adj[i].empty()) candidates.push_back(i);
        }

        for (int& c : candidates) {
            bool flag = true;
            for (int i = 1; i <= n; i++) {
                if (i != c && adj[i].count(c) == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) return c;
        }

        return -1;
    }
};