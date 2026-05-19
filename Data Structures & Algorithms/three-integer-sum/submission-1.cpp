class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            int j = 0, k = nums.size() - 1;
            int n1 = nums[i];
            while (j < k) {
                if (j != i && k != i && (nums[j] + nums[k] + n1) == 0) {
                    vector<int> pa = {n1, nums[j], nums[k]};
                    sort(pa.begin(), pa.end());
                    ans.insert(pa);
                    j++;
                    k--;
                }
                else if (j == i || (nums[j] + nums[k] + n1) < 0) j++;
                else if (k == i || (nums[j] + nums[k] + n1) > 0) k--;
            }
        }
        vector<vector<int>> fans;
        for (vector<int> it: ans) fans.push_back(it);
        return fans;        
    }
};
