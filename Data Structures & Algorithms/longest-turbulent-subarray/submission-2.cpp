class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int l = 0, r = 0, n = arr.size();
        bool big = true;
        int maxl = 1;
        while (r < n - 1) {
            if (big && arr[r + 1] > arr[r]) {
                r++;
                big = false;
                maxl = max(maxl, r - l + 1);
            }
            else if (!big && arr[r + 1] < arr[r]) {
                r++;
                big = true;
                maxl = max(maxl, r - l + 1);
            }
            else {
                r++;
                l = r;
                big = !big;
            }
        }

        big = false, l = 0, r = 0;
        while (r < n - 1) {
            if (big && arr[r + 1] > arr[r]) {
                r++;
                big = false;
                maxl = max(maxl, r - l + 1);
            }
            else if (!big && arr[r + 1] < arr[r]) {
                r++;
                big = true;
                maxl = max(maxl, r - l + 1);
            }
            else {
                r++;
                l = r;
                big = !big;
            }
        }

        return maxl;
    }
};