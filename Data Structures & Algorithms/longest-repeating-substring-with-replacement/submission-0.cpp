class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxl = 0;
        unordered_set<char> chars;
        for (int i = 0; i < s.size(); i++) chars.insert(s[i]);
        for (auto &letter : chars) {
            int others = 0;
            int l = 0;
            int r = 0;
            if (s[0] != letter) others++;
            while (l < s.size() && r < s.size()) {
                while (others <= k && r < s.size()) {
                    maxl = max(maxl, r - l + 1);
                    r++;
                    if (r < s.size() && s[r] != letter) others++;
                }
                while (others > k && l < s.size()) {
                    if (s[l] != letter) others--;
                    l++;
                }

            }
        }
        return maxl;
    }
};