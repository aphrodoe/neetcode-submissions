class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        for (int i = 0; i < order.size(); i++) mp[order[i]] = i;

        for (int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i], s2 = words[i + 1];
            int n = min(s1.size(), s2.size());
            bool flag = false;
            for (int i = 0; i < n; i++) {
                if (mp[s1[i]] > mp[s2[i]]) return false;
                else if (mp[s1[i]] < mp[s2[i]]) {
                    flag = true;
                    break;
                }
            }
            if (!flag && s1.size() > s2.size()) return false;
        }

        return true;
    }
};