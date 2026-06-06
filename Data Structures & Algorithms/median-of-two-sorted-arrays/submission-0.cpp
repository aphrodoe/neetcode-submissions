class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l = 0, r = 0;
        vector<int> merge;
        while (l < nums1.size() && r < nums2.size()) {
            if (nums1[l] < nums2[r]) {
                merge.push_back(nums1[l]);
                l++;
            }
            else {
                merge.push_back(nums2[r]);
                r++;
            }
        }
        while (l < nums1.size()) {
            merge.push_back(nums1[l]);
            l++;
        }
        while (r < nums2.size()) {
            merge.push_back(nums2[r]);
            r++;
        }
        if (merge.size() % 2) {
            return (double)merge[merge.size() / 2];
        } 
        else {
            double ans = ((double)merge[merge.size() / 2] + merge[merge.size() / 2 - 1]) / 2;
            return ans;
        }
    }
};
