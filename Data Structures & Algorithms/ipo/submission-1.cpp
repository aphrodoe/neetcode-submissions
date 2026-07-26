class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        priority_queue<int> pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> caps;
        for (int i = 0; i < n; i++) {
            caps.push({capital[i], i});
        }

        for (int i = 0; i < k; i++) {
            while (!caps.empty() && caps.top().first <= w) {
                int ind = caps.top().second;
                caps.pop();
                pq.push(profits[ind]);
            }
            if (pq.empty()) return w;
            int pr = pq.top();
            pq.pop();
            w += pr;
        }

        return w;

    }
};