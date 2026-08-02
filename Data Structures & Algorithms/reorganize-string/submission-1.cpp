class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        queue<pair<pair<int, char>, int>> q;
        unordered_map<char, int> mp;
        for (char& c : s) mp[c]++;
        for (auto& it : mp) pq.push({it.second, it.first});

        string ans;
        int pos = 0;
        while (!pq.empty() || !q.empty()) {
            while (!q.empty() && pos > q.front().second) {
                auto it = q.front();
                q.pop();
                pq.push({it.first.first, it.first.second});
            }
            if (pq.empty()) break;
            auto it = pq.top();
            pq.pop();
            ans.push_back(it.second);
            int cnt = it.first - 1;
            if (cnt > 0) q.push({{cnt, it.second}, pos + 1});
            pos++;
        }

        cout << ans;
        if (ans.size() != s.size()) return "";
        return ans;
    }
};