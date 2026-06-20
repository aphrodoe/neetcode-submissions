class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // node, cost
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> cost(n, INT_MAX);
        cost[src] = 0;
        // stops, cost, node
        priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, src}});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int stops = it.first;
            int cst = it.second.first;
            int node = it.second.second;
            if (stops == k + 1) break;

            for (auto it : adj[node]) {
                int newn = it.first;
                int ncst = it.second;
                if (cst + ncst < cost[newn]) {
                    cost[newn] = cst + ncst;
                    pq.push({stops + 1, {cost[newn], newn}});
                }
            }
        }

        return (cost[dst] == INT_MAX) ? -1 : cost[dst];
    }
};
