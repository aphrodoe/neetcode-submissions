class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (n > m) return false;

        vector<int> s1c(26, 0);
        vector<int> s2c(26, 0);
        for (int i = 0; i < n; i++) {
            s1c[s1[i] - 'a']++;
            s2c[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (s1c[i] == s2c[i]) matches++;
        }

        int l = 0;
        int r = n;
        while (r < m) {
            if (matches == 26) return true;

            int ind = s2[r] - 'a';
            s2c[ind]++;
            if (s1c[ind] == s2c[ind]) matches++;
            else if (s1c[ind] + 1 == s2c[ind]) matches--;

            ind = s2[l] - 'a';
            s2c[ind]--;
            if (s1c[ind] == s2c[ind]) matches++;
            else if (s1c[ind] - 1 == s2c[ind]) matches--;

            l++;
            r++;
        }

        return matches == 26;
    }
};
