class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() - 1, lb = r;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] >= x) {
                lb = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        deque<int> ans;
        int i = lb, j = lb - 1;
        while (ans.size() != k) {
            if (j < 0) ans.push_back(arr[i++]);
            else if (i >= arr.size()) ans.push_front(arr[j--]);
            else {
                if (abs(arr[i] - x) > abs(arr[j] - x)) ans.push_front(arr[j--]);
                else if (abs(arr[i] - x) < abs(arr[j] - x)) ans.push_back(arr[i++]);
                else {
                    if (arr[i] >= arr[j]) ans.push_front(arr[j--]);
                    else ans.push_back(arr[i++]);
                }
            }
        }

        return vector<int>(ans.begin(), ans.end());
    }
};