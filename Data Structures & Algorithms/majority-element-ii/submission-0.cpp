class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1 = nums[0], el2, cnt1 = 1, cnt2 = 0, pos = -1, n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] == el1) cnt1++;
            else {
                el2 = nums[i];
                cnt2 = 1;
                pos = i;
                break;
            }
        }
        
        if (pos == -1) return {el1};

        for (int i = pos + 1; i < n; i++) {
            if (cnt1 == 0 && nums[i] != el2) {
                el1 = nums[i];
                cnt1 = 1;
            }
            if (cnt2 == 0 && nums[i] != el1) {
                el2 = nums[i];
                cnt2 = 1;
            }
            else if (nums[i] == el1) cnt1++;
            else if (nums[i] == el2) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }

        vector<int> ans;
        int e1c = 0, e2c = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == el1) e1c++;
            else if (nums[i] == el2) e2c++;
        }

        if (e1c > n / 3) ans.push_back(el1);
        if (e2c > n / 3) ans.push_back(el2);

        return ans;
    }
};