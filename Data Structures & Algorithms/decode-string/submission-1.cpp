class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        stack<int> times;
        int t = 0;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch >= '0' && ch <= '9') {
                int dig = ch - '0';
                t = (t * 10) + dig;
            }
            else if (ch == '[') {
                times.push(t);
                t = 0;
                st.push("[");
            }
            else if (ch == ']') {
                string temp;
                while (st.top() != "[") {
                    temp.insert(temp.begin(), st.top().begin(), st.top().end());
                    st.pop();
                }
                st.pop();
                int rep = times.top();
                times.pop();
                string tempa;
                for (int i = 1; i <= rep; i++) tempa += temp;
                st.push(tempa);
            }
            else {
                string cha;
                cha.push_back(ch);
                st.push(cha);
            }
        }

        string ans;
        while (!st.empty()) {
            ans.insert(ans.begin(), st.top().begin(), st.top().end());
            st.pop();
        }

        return ans;
    }
};