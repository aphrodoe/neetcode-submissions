class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> next(2, vector<int>(2, -1)), curr(2, vector<int>(2, -1));
        next[0][0] = 0;
        next[0][1] = 0;
        next[1][0] = prices[n - 1];
        next[1][1] = prices[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            for (int b = 0; b <= 1; b++) {
                for (int c = 0; c <= 1; c++) {
                    int nothing = next[b][0], buy = INT_MIN, sell = INT_MIN;
                    if (b == 1) sell = prices[i] + next[0][1];
                    else if (b == 0 && c == 0) buy = -prices[i] + next[1][0];
                    curr[b][c] = max(nothing, max(buy, sell));
                }
            }
            next = curr;
        }

        return next[0][0];
    }
};