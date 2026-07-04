class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        queue<int> q;
        q.push(0);
        int farthest = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            int start = max(node + minJump, farthest + 1);

            for (int jump = start; jump < min(n, node + maxJump + 1); jump++) {
                if (s[jump] == '0') {
                    if (jump == n - 1) return true;
                    q.push(jump);
                }
            }
            farthest = node + maxJump;
        }

        return false;
        
    }
};