class Solution {
public:
    bool check(int i, string& s, unordered_set<string>& words, vector<int>& dp) {
        if (i == s.size()) return true;
        if (dp[i] != -1) return dp[i];
        string curr;
        for (int j = i; j < s.size(); j++) {
            curr.push_back(s[j]);
            if (words.find(curr) != words.end()) {
                if (check(j + 1, s, words, dp)) return dp[i] = true;
            }
        }
        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        unordered_set<string> words;
        for (int i = 0; i < n; i++) words.insert(wordDict[i]);
        vector<int> dp(s.size(), -1);

        return check(0, s, words, dp);
    }
};
