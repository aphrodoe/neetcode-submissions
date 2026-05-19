class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> n;
        for (int &i: nums) n.insert(i);

        int maxn = 0;
        for (int &i: nums) {
            if (n.find(i - 1) == n.end()) {
                int curr = 1, num = i;
                while (n.find(++num) != n.end()) curr++;
                maxn = max(maxn, curr);
            }
        }
        return maxn;
    }
};
