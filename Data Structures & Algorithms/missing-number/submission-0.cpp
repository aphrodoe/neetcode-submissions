class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int t = 0, c = 0;
        for (int i = 0; i <= nums.size(); i++) t ^= i;
        for (int& it: nums) c ^= it;
        return t ^ c;
    }
};
