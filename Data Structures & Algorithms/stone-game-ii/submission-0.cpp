class Solution {
public:
    int maxs(int m, int ind, int turn, vector<int>& piles, int n, vector<vector<vector<int>>>& dp) {
        if (ind == n) return 0;
        if (dp[m][ind][turn] != -1) return dp[m][ind][turn];
        int mscore = (turn) ? INT_MIN : INT_MAX; 
        int score, psum = 0;
        for (int i = ind; i <= min(n - 1, ind + 2 * m - 1); i++) {
            psum += piles[i];
            if (turn) {
                score = psum + maxs(max(i - ind + 1, m), i + 1, 0, piles, n, dp);
                mscore = max(mscore, score);
            }
            else {
                score = maxs(max(i - ind + 1, m), i + 1, 1, piles, n, dp);
                mscore = min(mscore, score);
            }
        }
        return dp[m][ind][turn] = mscore;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(101, vector<vector<int>>(101, vector<int>(2, -1)));
        return maxs(1, 0, 1, piles, n, dp);
    }
};