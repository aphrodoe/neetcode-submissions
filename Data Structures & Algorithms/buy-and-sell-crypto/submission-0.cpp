class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minp = prices[0], maxpr = 0;
        for (int i = 1; i < prices.size(); i++) {
            int pr = prices[i] - minp;
            maxpr = max(maxpr, pr);
            minp = min(minp, prices[i]);
        }
        return maxpr;
    }
};
