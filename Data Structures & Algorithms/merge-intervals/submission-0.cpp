class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i = 1, n = intervals.size();
        stack<vector<int>> st;
        st.push(intervals[0]);

        while (i < n) {
            while (i < n && intervals[i][0] <= st.top()[1]) {
                auto tp = st.top();
                st.pop();
                st.push({tp[0], max(tp[1], intervals[i][1])});
                i++;
            }
            if (i < n) {
                st.push(intervals[i]);
                i++;
            }
        }

        vector<vector<int>> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
