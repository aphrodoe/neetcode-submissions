class Solution {
public:
    bool check(vector<int>& weights, int maxw, int days) {
        int d = 0, currw = 0;
        for (int i = 0; i < weights.size(); i++) {
            currw += weights[i];
            if (currw > maxw) {
                d++;
                currw = weights[i];
            }
            if (i == weights.size() - 1) d++;
        }
        return (d <= days);
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end()), high = accumulate(weights.begin(), weights.end(), 0);
        int wc = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(weights, mid, days)) {
                wc = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return wc;
    }
};