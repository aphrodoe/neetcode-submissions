class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = intervals.size();
        int m = queries.size();

        vector<pair<int, int>> q;
        for (int i = 0; i < m; i++) q.push_back({queries[i], i});
        sort(intervals.begin(), intervals.end());
        sort(q.begin(), q.end());

        vector<int> ans(m, -1);
        int j = 0;
        for (int i = 0; i < m; i++) {
            auto qr = q[i];
            while (j < n && intervals[j][0] <= qr.first) {
                pq.push({(intervals[j][1] - intervals[j][0] + 1), intervals[j][1]});
                j++;
            }
            while (!pq.empty() && pq.top().second < qr.first) pq.pop();
            if (!pq.empty()) ans[qr.second] = pq.top().first;
        }
        return ans;


    }
};
