class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ma = 0, n = heights.size();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int el = heights[st.top()];
                st.pop();
                int pse = (!st.empty()) ? st.top() : -1;
                int nse = i;
                int area = el * (nse - pse - 1);
                ma = max(ma, area);
            }
            st.push(i);
        }

        while (!st.empty()) {
            int nse = n;
            int el = heights[st.top()];
            st.pop();
            int pse = (!st.empty()) ? st.top() : -1;
            int area = el * (nse - pse - 1);
            ma = max(ma, area);
        }

        return ma;
    }
};