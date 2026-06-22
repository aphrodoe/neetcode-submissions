class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = 0, prev1 = 0, curr;
        for (int i = 2; i <= n; i++) {
            int os = prev1 + cost[i - 1];
            int ts = INT_MAX;
            if (n > 1) ts = prev2 + cost[i - 2];
            curr = min(os, ts);
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};
