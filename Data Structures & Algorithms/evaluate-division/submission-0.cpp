class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> mp;
        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0], v = equations[i][1];
            double val = values[i];
            mp[u][v] = val;
            mp[v][u] = 1 / val;
            mp[u][u] = 1.0;
            mp[v][v] = 1.0;
        }

        for (auto& it1 : mp) {
            string via = it1.first;
            for (auto& it2 : mp) {
                string s1 = it2.first;
                for (auto& it3 : mp) {
                    string s2 = it3.first;
                    if (mp[s1].count(via) && mp[via].count(s2)) {
                        mp[s1][s2] = mp[s1][via] * mp[via][s2];
                    }
                }
            }
        }

        vector<double> ans;
        for (int i = 0; i < queries.size(); i++) {
            string s1 = queries[i][0], s2 = queries[i][1];
            if (!mp.count(s1) || !mp[s1].count(s2)) ans.push_back(-1.0);
            else ans.push_back(mp[s1][s2]);
        }

        return ans;
    }
};