class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = 0;
        int ni = 0;
        for (int i = 0; i <= 62; i++) {
            int d1 = ((long long)x >> i) & 1;
            if (d1 == 1) {
                ans |= (1LL << i);
                continue;
            }
            int d2 = (((long long)(n - 1) >> ni) & 1);
            ni++;
            if (d2 == 1) ans |= (1LL << i);
        }
        return ans;
    }
};