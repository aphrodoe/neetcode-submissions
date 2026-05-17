class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++) {
            vector<int> count(26, 0);
            for (auto it: strs[i]) {
                count[it - 'a']++;
            }
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += to_string(count[i]) + ",";
            }
            mp[key].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (auto it: mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
