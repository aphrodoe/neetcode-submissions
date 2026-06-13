class Solution {
public:
    void generate(vector<string>& ans, string curr, stack<char>& st, int n) {
        if (curr.size() == n) {
            if (st.empty()) ans.push_back(curr);
            return;
        }
        st.push('(');
        generate(ans, curr + "(", st, n);
        st.pop();
        if (!st.empty() && st.top() == '(') {
            st.pop();
            generate(ans, curr + ")", st, n);
            st.push('(');
        }
    }

    vector<string> generateParenthesis(int n) {
        stack<char> st;
        vector<string> ans;

        generate(ans, "", st, 2 * n);

        return ans;
    }
};