class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0, ip = m;
        if (ip >= nums1.size()) return;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                nums1[ip] = nums1[i];
                ip = (ip + 1) % (m + n);
                i++;
            }
            else {
                nums1[ip] = nums2[j];
                ip = (ip + 1) % (m + n);
                j++;
            }
        }
        while (i < m) {
            nums1[ip] = nums1[i];
            ip = (ip + 1) % (m + n);
            i++;
        }
        while (j < n) {
            nums1[ip] = nums2[j];
            ip = (ip + 1) % (m + n);
            j++;
        }
        reverse(nums1.begin(), nums1.begin() + m);
        reverse(nums1.begin() + m, nums1.end());
        reverse(nums1.begin(), nums1.end());
    }
};