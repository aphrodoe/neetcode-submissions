class Solution {
public:
    double powr(double x, long long nl) {
        if (nl == 0) return 1.0;
        double hf = powr(x, nl / 2);
        if (nl % 2) return x * hf * hf;
        else return hf * hf;
    }

    double myPow(double x, int n) {
        long long nl = n;
        if (n < 0) {
            x = (1 / x);
            nl = -n;
        }
        return powr(x, nl);
    }
};
