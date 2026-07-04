class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        deque<int> d, r;
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') r.push_back(i);
            else d.push_back(i);
        }

        vector<int> rem(n, 0);
        while (!(d.empty() || r.empty())) {
            for (int i = 0; i < n; i++) {
                if (rem[i]) continue;
                if (senate[i] == 'R') {
                    if (d.empty()) break;
                    int first = d.front();
                    d.pop_front();
                    if (first > i) {
                        rem[first] = 1;
                        continue;
                    }
                    d.push_back(first);
                    while (d.front() < i && d.front() != first) {
                        d.push_back(d.front());
                        d.pop_front();
                    }
                    first = d.front();
                    d.pop_front();
                    rem[first] = 1;
                }
                else {
                    if (r.empty()) break;
                    int first = r.front();
                    r.pop_front();
                    if (first > i) {
                        rem[first] = 1;
                        continue;
                    }
                    r.push_back(first);
                    while (r.front() < i && r.front() != first) {
                        r.push_back(r.front());
                        r.pop_front();
                    }
                    first = r.front();
                    r.pop_front();
                    rem[first] = 1;
                }
            }
        }

        if (d.empty()) return "Radiant";
        else return "Dire";
    }
};