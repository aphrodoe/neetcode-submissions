class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int maxs = 0;
        int i = 0, j = 0;
        while (i < s.size() && j < s.size()) {
            if (!mp[s[j]]) {
                mp[s[j]] = 1;
                j++;
            }
            else {
                maxs = max(maxs, j - i);
                while (mp[s[j]]) {
                    mp.erase(s[i]);
                    i++;
                }
            }
        }
        maxs = max(maxs, j - i);
        return maxs;
    }
};
