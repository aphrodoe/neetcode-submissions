class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size() - 1;
        int amax = 0;
        while (i < j) {
            amax = max(amax, min(heights[i], heights[j]) * (j - i));
            if (heights[i] < heights[j]) i++;
            else j--;
        }
        return amax;
    }
};
