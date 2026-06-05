class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        int n = s.size();
        int m = t.size();
        int l = 0;
        int r = 0;
        int cnt = 0;
        int minlen = INT_MAX;
        int sindex = -1;
        for (int i = 0; i < m; i++) mp[t[i]]++;
        while (r < n) {
            if (mp[s[r]] > 0) cnt++;
            mp[s[r]]--;
            while (cnt == m) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    sindex = l;
                }
                mp[s[l]]++;
                if (mp[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        return (sindex == -1) ? "" : s.substr(sindex, minlen);
    }
};