class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int n1 = nums[i];
            int n2 = target - n1;
            if (mp.find(n2) != mp.end()) return vector<int> {mp[n2], i};
            if (mp.find(n1) == mp.end()) mp[n1] = i;
        }
    }
};
