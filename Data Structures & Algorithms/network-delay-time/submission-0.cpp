class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> time(n + 1, INT_MAX);
        time[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int t = it.first;
            int node = it.second;

            for (auto it : adj[node]) {
                int newn = it.first;
                int nt = it.second;
                if (t + nt < time[newn]) {
                    time[newn] = t + nt;
                    pq.push({time[newn], newn});
                }
            }
        }

        int mint = *max_element(time.begin() + 1, time.end());
        return (mint == INT_MAX) ? -1 : mint;
    }
};
