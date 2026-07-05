class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100},
                                        {'D', 500}, {'M', 1000}};
        int n = s.size();
        int num = 0;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == 'I' && i < n - 1) {
                if (s[i + 1] == 'V') {
                    num += 4;
                    i++;
                    continue;
                }
                else if (s[i + 1] == 'X') {
                    num += 9;
                    i++;
                    continue;
                }
            }
            else if (c == 'X' && i < n - 1) {
                if (s[i + 1] == 'L') {
                    num += 40;
                    i++;
                    continue;
                }
                else if (s[i + 1] == 'C') {
                    num += 90;
                    i++;
                    continue;
                }
            }
            else if (c == 'C' && i < n - 1) {
                if (s[i + 1] == 'D') {
                    num += 400;
                    i++;
                    continue;
                }
                else if (s[i + 1] == 'M') {
                    num += 900;
                    i++;
                    continue;
                }
            }
            num += mp[c];
        }
        return num;
    }
};