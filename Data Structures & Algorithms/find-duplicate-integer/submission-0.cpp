class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int& n: nums) {
            if (mp.find(n) != mp.end()) return n;
            else mp[n] = 1;
        }
        
    }
};
