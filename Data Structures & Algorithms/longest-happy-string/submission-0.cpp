class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a != 0) pq.push({a, 'a'});
        if (b != 0) pq.push({b, 'b'});
        if (c != 0) pq.push({c, 'c'});
        string s;
        while (!pq.empty()) {
            auto it = pq.top();
            char c = it.second;
            int f = it.first;
            pq.pop();
            int n = s.size();
            if (n >= 2 && s[n - 1] == c && s[n - 2] == c) {
                if (pq.empty()) break;
                auto it1 = pq.top();
                pq.pop();
                char c1 = it1.second;
                int f1 = it1.first;
                s += c1;
                f1--;
                if (f1 != 0) pq.push({f1, c1});
                pq.push({f, c});
            }
            else {
                s += c;
                f--;
                if (f != 0) pq.push({f, c});
            }
        }
        return s;
    }
};