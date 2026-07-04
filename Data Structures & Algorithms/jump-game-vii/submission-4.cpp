class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int jump = maxJump; jump >= minJump; jump--) {
                int nextn = node + jump;
                if (nextn >= n) continue;
                if (s[nextn] == '1') continue;

                if (nextn == n - 1) return true;

                if (nextn + minJump >= n) continue;

                q.push(nextn);
                break;
            }
        }

        return false;
        
    }
};