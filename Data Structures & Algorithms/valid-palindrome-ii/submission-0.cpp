class Solution {
public:
    bool check(int i, int j, string s) {
        if (i >= j) return true;
        if (s[i] == s[j]) return check(i + 1, j - 1, s);
        else return false;
    }

    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            }
            else {
                if (check(i + 1, j, s)) return true;
                else if (check(i, j - 1, s)) return true;
                else return false;
            }
        }
        return true;
    }
};