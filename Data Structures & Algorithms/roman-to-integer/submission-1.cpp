class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100},
                                        {'D', 500}, {'M', 1000}};
        int n = s.size();
        int num = 0;
        for (int i = 0; i < n; i++) {
            if (i < n - 1 && mp[s[i + 1]] > mp[s[i]]) num -= mp[s[i]];
            else num += mp[s[i]];
        }
        return num;
    }
};