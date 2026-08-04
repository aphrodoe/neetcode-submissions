class Solution {
public:
    int minc(int ind, string& s, unordered_set<string>& d, vector<int>& dp) {
        if (ind >= s.size()) return 0;
        if (dp[ind] != -1) return dp[ind];
        int mine = s.size() - ind;
        for (int i = ind; i < (int)s.size(); i++) {
            for (int j = i; j < (int)s.size(); j++) {
                string curr = s.substr(i, j - i + 1);
                if (d.find(curr) != d.end()) {
                    mine = min(mine, i - ind + minc(j + 1, s, d, dp));
                }
            }
        }
        return dp[ind] = mine;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict;
        for (string& s : dictionary) dict.insert(s);
        int n = s.size();
        vector<int> dp(n, -1);
        return minc(0, s, dict, dp);
    }
};