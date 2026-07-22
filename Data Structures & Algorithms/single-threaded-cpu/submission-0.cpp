class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>>> enqueue; // enqueue, index
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>>> time; // processing time, index

        for (int i = 0; i < tasks.size(); i++) {
            enqueue.push({tasks[i][0], i});
        }

        int timer = 1;
        vector<int> order;
        while (!enqueue.empty() || !time.empty()) {
            while (!enqueue.empty() && timer >= enqueue.top().first) {
                auto it = enqueue.top();
                enqueue.pop();
                int ind = it.second;
                time.push({tasks[ind][1], ind});
            }
            if (!enqueue.empty() && time.empty()) {
                timer = enqueue.top().first;
                continue;
            }
            auto it = time.top();
            time.pop();
            int ptime = it.first, ind = it.second;
            order.push_back(it.second);
            timer += ptime;
        }

        return order;
    }
};