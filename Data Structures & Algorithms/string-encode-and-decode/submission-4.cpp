class Solution {
public:

    string encode(vector<string>& strs) {
        string enc;
        for (string& s: strs) {
            enc += to_string(s.size()) + "$" + s;
        }
        return enc;
    }

    vector<string> decode(string s) {
        vector<string> dec;
        int len = 0, i = 0;
        while (i < s.size()) {
            while (i < s.size() && s[i] != 36) {
                len = (len * 10) + (int)(s[i] - '0');
                i++;
            }
            if (i >= s.size()) break;
            i++;
            dec.push_back(s.substr(i, len));
            i += len;
            len = 0;
        }
        return dec;
    }
};
