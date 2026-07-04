class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        queue<int> q;
        vector<int> vis(n, 0);
        q.push(0);
        vis[0] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int jump = minJump; jump <= maxJump; jump++) {
                int nextn = node + jump;
                if (nextn >= n) continue;
                if (s[nextn] == '1') continue;

                if (nextn == n - 1) return true;

                if (!vis[nextn]) {
                    vis[nextn] = 1;
                    q.push(nextn);
                }
            }
        }

        return false;
        
    }
};