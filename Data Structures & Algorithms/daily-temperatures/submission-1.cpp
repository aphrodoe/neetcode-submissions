class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> result(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && temperatures[i] >= temperatures[st.top()]) st.pop();
            int nw = (!st.empty()) ? st.top() : -1;
            st.push(i);
            if (nw == -1) result[i] = 0;
            else {
                result[i] = nw - i;
            }
        }
        return result;
    }
};
