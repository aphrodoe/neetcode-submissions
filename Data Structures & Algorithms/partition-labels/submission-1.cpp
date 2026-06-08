class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        int n = s.size();

        for (int i = 0; i < n; i++) mp[s[i]] = i;

        int i = 0, start = 0, end = -1;
        vector<int> ind;
        while (i < n) {
            end = max(end, mp[s[i]]);
            if (i == end) {
                ind.push_back(end - start + 1);
                start = i + 1;
                end = -1;
            }
            i++;
        }
        return ind;
    }
};
