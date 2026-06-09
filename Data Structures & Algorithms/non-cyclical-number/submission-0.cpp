class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> mp;
        while (n != 1) {
            int s = 0;
            while (n != 0) {
                s += (n % 10) * (n % 10);
                n /= 10;
            }
            if (mp.find(s) != mp.end()) return false;
            else mp[s] = 1;
            n = s;
        }
        return true;
    }
};
