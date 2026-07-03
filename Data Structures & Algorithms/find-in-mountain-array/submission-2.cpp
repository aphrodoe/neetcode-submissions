/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeak(MountainArray& mountainArr, int low, int high, int n) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int nm = mountainArr.get(mid);
            int nb = (mid - 1 > 0) ? mountainArr.get(mid - 1) : INT_MIN;
            int na = (mid + 1 < n) ? mountainArr.get(mid + 1) : INT_MIN;
            if (nm > nb && na > nm) low = mid + 1;
            else if (nm < nb && na < nm) high = mid - 1;
            else return mid;
        }
        return -1;
    }

    int bin(MountainArray& mountainArr, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int nm = mountainArr.get(mid);
            if (nm == target) return mid;
            else if (nm > target) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }

    int rbin(MountainArray& mountainArr, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int nm = mountainArr.get(mid);
            if (nm == target) return mid;
            else if (nm > target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int low = 0, high = mountainArr.length() - 1;
        int peak = findPeak(mountainArr, low, high, high + 1);

        int nl = mountainArr.get(low);
        int nr = mountainArr.get(high);
        int np = mountainArr.get(peak);

        int n1 = -1, n2 = -1;
        n1 = bin(mountainArr, low, peak, target);
        n2 = rbin(mountainArr, peak + 1, high, target);

        return (n1 == -1) ? n2 : n1;

    }
};