class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size(), i = 0;
        bool ni = false;
        if (n > 0 && intervals[0][0] > newInterval[1]) {
            ans.push_back(newInterval);
            ni = true;
        }
        while (i < n) {
            if (ni) {
                ans.push_back(intervals[i]);
                i++;
            }
            else if (intervals[i][1] < newInterval[0]) {
                ans.push_back(intervals[i]);
                i++;
            }
            else if (intervals[i][0] > newInterval[1]) {
                ans.push_back(newInterval);
                ni = true;
            }
            else {
                ni = true;
                int begin = min(intervals[i][0], newInterval[0]);
                int end = max(intervals[i][1], newInterval[1]);
                i++;
                while (i < n && intervals[i][0] <= end) {
                    end = max(end, intervals[i][1]);
                    i++;
                }
                ans.push_back({begin, end});
            }
        }
        if (!ni) ans.push_back(newInterval);  
        return ans;      
    }
};