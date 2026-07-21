class Solution {
public:
    int scorea(int ind, int turn, vector<int>& stones, int n, vector<vector<int>>& dp) {
        if (ind == n) return 0;
        if (dp[ind][turn] != -1) return dp[ind][turn];
        int sum = 0;
        int mscore = (turn == 1) ? INT_MIN : INT_MAX;
        for (int i = ind; i < min(n, ind + 3); i++) {
            sum += stones[i];
            if (turn) {
                int score = sum + scorea(i + 1, 0, stones, n, dp);
                mscore = max(mscore, score);
            }
            else {
                int score = scorea(i + 1, 1, stones, n, dp);
                mscore = min(mscore, score);
            }
        }
        return dp[ind][turn] = mscore;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        int alice = scorea(0, 1, stoneValue, n, dp);
        int bob = accumulate(stoneValue.begin(), stoneValue.end(), 0) - alice;
        if (alice > bob) return "Alice";
        else if (alice < bob) return "Bob";
        else return "Tie";
    }
};