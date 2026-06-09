class Solution {
public:
    int reverse(int x) {
        bool sign = (x < 0) ? false : true;
        long long n;
        if (!sign) n = -1 * (long long)x;
        else n = (long long)x;
        long long rev = 0;
        
        while (n != 0) {
            int dig = n % 10;
            n /= 10;
            rev = (rev * 10) + dig;
        }

        if (sign && rev > INT_MAX) return 0;
        if (!sign && rev > (long long)INT_MAX + 1) return 0;

        return (sign) ? (int)rev : -1 * (int)rev;
        
    }
};
