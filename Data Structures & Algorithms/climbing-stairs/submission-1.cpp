class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 1, prev1 = 2, curr;
        if (n == 1) return prev2;
        if (n == 2) return prev1;
        for (int i = 3; i <= n; i++) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};
