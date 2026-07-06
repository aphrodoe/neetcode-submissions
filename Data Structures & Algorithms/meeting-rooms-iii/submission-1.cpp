class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> cnt(n, 0);
        priority_queue<int, vector<int>, greater<int>> emp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> full;
        for (int i = 0; i < n; i++) emp.push(i);

        for (int i = 0; i < meetings.size(); i++) {
            vector<int> meet = meetings[i];
            while (!full.empty() && meet[0] >= full.top().first) {
                emp.push(full.top().second);
                full.pop();
            }
            if (emp.empty()) {
                auto it = full.top();
                int end = it.first;
                int room = it.second;
                cnt[room]++;
                full.pop();
                int dur = meet[1] - meet[0];
                full.push({end + dur, room});
            }
            else {
                int room = emp.top();
                emp.pop();
                cnt[room]++;
                full.push({meet[1], room});
            }
        }

        int maxr = -1, maxm = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (cnt[i] > maxm) {
                maxm = cnt[i];
                maxr = i;
            }
        }

        return maxr;
    }   
};