class Solution {
public:
    int mySqrt(int x) {
        long long low = 0, high = x;
        int sqrt;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (mid * mid <= x) {
                sqrt = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return sqrt;
    }
};