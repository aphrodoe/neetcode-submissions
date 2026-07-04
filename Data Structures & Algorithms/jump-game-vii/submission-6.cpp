class Solution {
public:
    bool check(int i, string& s, int minJump, int maxJump, int n, vector<int>& dp) {
        if (i == n - 1) {
            if (s[i] == '0') return true;
            else return false;
        }
        if (dp[i] != -1) return dp[i];
        if (s[i] == '1') return dp[i] = false;
        for (int jump = maxJump; jump >= minJump; jump--) {
            int next = i + jump;
            if (i + jump >= n) continue;
            if (check(i + jump, s, minJump, maxJump, n, dp)) return dp[i] = true;
        }
        return dp[i] = false;
    }

    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> dp(n, -1);
        return check(0, s, minJump, maxJump, n, dp);
    }
};