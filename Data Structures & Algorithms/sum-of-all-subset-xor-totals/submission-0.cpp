class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (int i = 0; i < (1 << n); i++) {
            int xs = 0;
            for (int j = 0; j < n; j++) {
                int choose = (i >> j) & 1;
                if (choose) xs ^= nums[j];
            }
            sum += xs;
        }
        return sum;
    }
};