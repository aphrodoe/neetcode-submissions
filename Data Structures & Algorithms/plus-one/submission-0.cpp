class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1, c = 0;
        if (digits[n] == 9) {
            digits[n] = 0;
            c = 1;
        }
        else digits[n]++;
        if (!c) return digits;
        else {
            int r = n - 1;
            while (r >= 0 && c == 1) {
                if (digits[r] != 9) {
                    digits[r]++;
                    c = 0;
                }
                else {
                    digits[r] = 0;
                    r--;
                }
            }
            if (c == 1) digits.insert(digits.begin(), 1);
        }
        return digits;
        
    }
};
