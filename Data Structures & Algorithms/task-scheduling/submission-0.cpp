class Solution {
public:

    class Compare {
    public:
        bool operator()(pair<char, int> a, pair<char, int> b) {
            return a.second < b.second;
        }
    };

    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> start;
        unordered_map<char, int> cnt;

        for (int i = 0; i < tasks.size(); i++) cnt[tasks[i]]++;

        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> pq;
        for (auto& it: cnt) pq.push({it.first, it.second});

        int i = 0;
        while (!pq.empty()) {
            if (start.find(pq.top().first) == start.end()) {
                start[pq.top().first] = ++i;
                if (pq.top().second == 1) pq.pop();
                else {
                    auto it = pq.top();
                    pq.pop();
                    it.second--;
                    pq.push(it);
                }
            }
            else {
                vector<pair<char, int>> v;
                while (!pq.empty() && start.find(pq.top().first) != start.end() && i - start[pq.top().first] < n) {
                    v.push_back(pq.top());
                    pq.pop();
                }
                if (pq.empty()) {
                    ++i;
                    for (int j = 0; j < v.size(); j++) pq.push(v[j]);
                    continue;
                }
                start[pq.top().first] = ++i;
                if (pq.top().second == 1) pq.pop();
                else {
                    auto it = pq.top();
                    pq.pop();
                    it.second--;
                    pq.push(it);
                } 
                for (int j = 0; j < v.size(); j++) pq.push(v[j]);  
            }
        }

        return i;

    }
};