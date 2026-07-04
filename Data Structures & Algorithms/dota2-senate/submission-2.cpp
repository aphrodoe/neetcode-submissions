class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        deque<int> d, r;
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') r.push_back(i);
            else d.push_back(i);
        }

        while (!d.empty() && !r.empty()) {
            int fd = d.front();
            int fr = r.front();
            d.pop_front();
            r.pop_front();
            if (fd < fr) d.push_back(fd + n);
            else r.push_back(fr + n);
        }

        if (d.empty()) return "Radiant";
        else return "Dire";
    }
};