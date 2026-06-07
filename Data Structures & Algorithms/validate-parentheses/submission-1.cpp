class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto& ch: s) {
            if (ch == '(' || ch == '[' || ch == '{') st.push(ch);
            else if ((ch == ')' || ch == ']' || ch == '}') && st.empty()) return false; 
            else if (ch == ')') {
                if (st.top() == '(') {
                    st.pop();
                    continue;
                }
                else return false;
            }
            else if (ch == ']') {
                if (st.top() == '[') {
                    st.pop();
                    continue;
                }
                else return false;
            }
            else if (ch == '}') {
                if (st.top() == '{') {
                    st.pop();
                    continue;
                }
                else return false;
            }
        }
        if (st.empty()) return true;
        else return false;
    }
};
