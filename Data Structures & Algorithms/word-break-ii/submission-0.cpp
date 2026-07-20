class Solution {
public:
    void ways(string& s, unordered_set<string>& words, vector<vector<string>>& ans, vector<string>& curr, int ind) {
        if (ind == s.size()) {
            ans.push_back(curr);
            return;
        }
        for (int i = ind; i < s.size(); i++) {
            string subs = s.substr(ind, i - ind + 1);
            if (words.count(subs)) {
                curr.push_back(subs);
                ways(s, words, ans, curr, i + 1);
                curr.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for (string& str : wordDict) words.insert(str);
        vector<vector<string>> ans;
        vector<string> curr;
        ways(s, words, ans, curr, 0);

        vector<string> ansf;
        for (int i = 0; i < ans.size(); i++) {
            string str;
            for (int j = 0; j < ans[i].size(); j++) {
                str += ans[i][j];
                if (j != ans[i].size() - 1) str.push_back(' ');
            }
            ansf.push_back(str);
        }
        return ansf;
    }
};