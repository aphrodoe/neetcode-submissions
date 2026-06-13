class Solution {
public:
    bool checkp(string s) {
        int i = 0, j = s.size() - 1;
        while (i <= j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void generate(vector<vector<string>>& ans, vector<string>& curr, string& s, int index) {
        if (index == s.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (checkp(s.substr(index, i - index + 1))) {
                curr.push_back(s.substr(index, i - index + 1));
                generate(ans, curr, s, i + 1);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;

        generate(ans, curr, s, 0);

        return ans;
    }
};
