class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int cnt = 1;
        vector<int> curr = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= curr[1]) {
                cnt++;
                curr = intervals[i];
            }
        }
        return intervals.size() - cnt;
    }
};