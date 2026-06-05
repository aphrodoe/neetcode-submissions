class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(), s1.end());
        for (int i = 0; i < s2.size() - s1.size() + 1; i++) {
            string sub = s2.substr(i, s1.size());
            sort(sub.begin(), sub.end());
            if (sub == s1) return true;
        }
        return false;
    }
};
