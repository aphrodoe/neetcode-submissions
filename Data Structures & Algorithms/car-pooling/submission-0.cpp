class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int cap = capacity;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        sort(trips.begin(), trips.end(), comp);
        for (int i = 0; i < trips.size(); i++) {
            int pas = trips[i][0], from = trips[i][1], to = trips[i][2];
            while (!pq.empty() && from >= pq.top().first) {
                cap += pq.top().second;
                pq.pop();
            }
            if (pas > cap) return false;
            cap -= pas;
            pq.push({to, pas});
        }
        return true;
    }
};