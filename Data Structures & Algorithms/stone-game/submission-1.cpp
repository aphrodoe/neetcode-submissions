class Solution {
public:
    int maxs(int l, int r, vector<int>& piles, vector<vector<int>>& dp) {
        if (l > r) return 0;
        if (dp[l][r] != -1) return dp[l][r];
        int even = (l + r + 1) % 2; 
        int left = (even) ? piles[l] : 0;
        int right = (even) ? piles[r] : 0;
        return dp[l][r] = max(left + maxs(l + 1, r, piles, dp), right + maxs(l, r - 1, piles, dp));
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ascore = maxs(0, n - 1, piles, dp);
        int bscore = accumulate(piles.begin(), piles.end(), 0) - ascore;
        return (ascore > bscore);
    }
};