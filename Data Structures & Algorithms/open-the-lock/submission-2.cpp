class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead;
        for (int i = 0; i < deadends.size(); i++) dead.insert(deadends[i]);

        if (dead.count("0000")) return -1;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> q;
        vector<int> dist(10000, 1e9);
        q.push({0, "0000"});
        dist[0] = 0;

        while (!q.empty()) {
            auto it = q.top();
            q.pop();
            int d = it.first;
            string s = it.second;

            if (s == target) return d;

            for (int i = 0; i < 4; i++) {
                int dig = s[i] - '0';
                int plus = (dig + 1) % 10;
                int minus = (dig == 0) ? 9 : dig - 1;
                s[i] = plus + '0';
                if (dead.count(s) == 0 && 1 + d < dist[stoi(s)]) {
                    dist[stoi(s)] = 1 + d;
                    q.push({1 + d, s});
                }
                s[i] = minus + '0';
                if (dead.find(s) == dead.end() && 1 + d < dist[stoi(s)]) {
                    dist[stoi(s)] = 1 + d;
                    q.push({1 + d, s});
                }
                s[i] = dig + '0';
            }
        }

        return -1;
    }
};