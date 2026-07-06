class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int band = 0;
        for (int i = 31; i >= 0; i--) {
            int l = (left >> i) & 1, r = (right >> i) & 1;
            if (l == r) band |= (l << i);
            else break;
        }
        return band;
    }
};