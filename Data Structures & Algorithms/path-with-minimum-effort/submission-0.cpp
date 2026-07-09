class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<int> drow = {-1, 1, 0, 0};
        vector<int> dcol = {0, 0, -1, 1};
        int n = heights.size(), m = heights[0].size();

        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        effort[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int eff = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (r == n - 1 && c == m - 1) return eff;
            
            for (int i = 0; i < 4; i++) {
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int neff = max(eff, abs(heights[nr][nc] - heights[r][c]));
                    if (neff < effort[nr][nc]) {
                        effort[nr][nc] = neff;
                        pq.push({neff, {nr, nc}});
                    }
                }
            }
        }
    }
};