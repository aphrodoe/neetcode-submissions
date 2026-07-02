class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                long long csum = (long long)nums[i] + nums[j];
                long long remt = target - csum;
                int k = j + 1, l = n - 1;
                while (k < l) {
                    long long sum = (long long)nums[k] + nums[l];
                    if (sum < remt) k++;
                    else if (sum > remt) l--;
                    else {
                        vector<int> quad = {nums[i], nums[j], nums[k], nums[l]};
                        s.insert(quad);
                        k++;
                        l--;
                    }
                }
            }
        }
        vector<vector<int>> ans(s.begin(), s.end());

        return ans;
    }
};