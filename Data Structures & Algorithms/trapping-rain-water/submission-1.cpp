class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lmax = height[l], rmax = height[r];
        int water = 0;
        while (l < r) {
            if (lmax < rmax) {
                l++;
                lmax = max(lmax, height[l]);
                water += lmax - height[l];
            }
            else {
                r--;
                rmax = max(rmax, height[r]);
                water += rmax - height[r];
            }
        }
        return water;
    }
};
