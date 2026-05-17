class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num: nums) {
            mp[num]++;
        }
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& it: mp) {
            int num = it.first;
            int freq = it.second;
            buckets[freq].push_back(num);
        }
        vector<int> ans;
        for (int i = nums.size(); i >= 0 && ans.size() < k; i--) {
            for (int num: buckets[i]) {
                ans.push_back(num);
                if (ans.size() == k) return ans;
            }
        }
        return ans;
    }
};
