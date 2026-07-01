class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];

        int len = 0, mlen = INT_MAX;
        for (int i = 1; i < strs.size(); i++) {
            string prev = strs[i - 1];
            string curr = strs[i];
            while (len < prev.size() && len < curr.size() && prev[len] == curr[len]) len++;
            mlen = min(mlen, len);
            len = 0;
        }

        return strs[0].substr(0, mlen);
    }
};