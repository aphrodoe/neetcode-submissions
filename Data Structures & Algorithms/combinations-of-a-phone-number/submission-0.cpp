class Solution {
public:
    void generate(vector<string>& ans, string& curr, string& digits, unordered_map<char, string>& mp, int index) {
        if (index == digits.size()) {
            if (curr.size() == digits.size()) ans.push_back(curr);
            return;
        }

        for (int i = index; i < digits.size(); i++) {
            string s = mp[digits[i]];
            for (char& c : s) {
                curr.push_back(c);
                generate(ans, curr, digits, mp, i + 1);
                curr.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return vector<string> {};
        
        unordered_map<char, string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        vector<string> ans;
        string curr;

        generate(ans, curr, digits, mp, 0);

        return ans;
    }
};