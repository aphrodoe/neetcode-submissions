class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxr(n, 0);
        int hr = height[n - 1], hl = height[0];
        int water = 0;
        for (int i = n - 2; i >= 0; i--) {
            maxr[i] = hr;
            hr = max(hr, height[i]);
        }
        for (int i = 1; i < n; i++) {
            int w = min(hl, maxr[i]) - height[i];
            if (w > 0) water += w;
            hl = max(hl, height[i]);
        }
        return water;
    }
};
