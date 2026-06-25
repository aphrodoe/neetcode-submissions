class Solution {
public:
    int cnt(int ind, string curr, string s, string target, vector<unordered_map<string, int>>& dp) {
        if (ind == 0) {
            if (curr == target) return 1;
            else if (curr + s[0] == target) return 1;
            else return 0;
        }
        if (dp[ind].find(curr) != dp[ind].end()) return dp[ind][curr];
        int notpick = cnt(ind - 1, curr, s, target, dp);
        int pick = 0;
        if (curr.size() != target.size()) pick = cnt(ind - 1, curr + s[ind], s, target, dp);
        return dp[ind][curr] = notpick + pick;
    } 

    int numDistinct(string s, string t) {
        int n = s.size();
        vector<unordered_map<string, int>> dp(n);
        reverse(t.begin(), t.end());
        return cnt(n - 1, "", s, t, dp);
    }
};