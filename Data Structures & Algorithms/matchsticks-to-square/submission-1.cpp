class Solution {
public:
    bool check(vector<int>& match, vector<int>& sum, int k, int ind) {
        if (ind == match.size()) return true;
        for (int i = 0; i < 4; i++) {
            if (sum[i] + match[ind] <= k) {
                sum[i] += match[ind];
                if (check(match, sum, k, ind + 1)) return true;
                sum[i] -= match[ind];
            }
            if (sum[i] == 0) return false;
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int s = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (s % 4 != 0) return false;
        int k = s / 4;
        vector<int> sum(4, 0);
        sort(matchsticks.begin(), matchsticks.end());
        return check(matchsticks, sum, k, 0);
    }
};