class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {
            string s = tokens[i];
            if (s != "+" && s != "-" && s != "*" && s != "/") st.push(stoi(s));
            else {
                int t1 = st.top();
                st.pop();
                int t2 = st.top();
                st.pop();
                if (s == "+") st.push(t2 + t1);
                else if (s == "-") st.push(t2 - t1);
                else if (s == "*") st.push(t2 * t1);
                else st.push(t2 / t1);
            }
        }
        return st.top();
    }
};
