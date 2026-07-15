class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string temp;
        for (int i = 0; i < path.size(); i++) {
            if ((path[i] == '/' && !temp.empty())) {
                if (temp == ".") temp = "";
                else if (temp == "..") {
                    if (!st.empty()) st.pop();
                    temp = "";
                }
                else {
                    st.push(temp);
                    temp = "";
                }
            }
            else if (path[i] == '/') continue;
            else temp.push_back(path[i]);
        }

        if (!temp.empty()) {
            if (temp == ".") temp = "";
            else if (temp == "..") {
                if (!st.empty()) st.pop();
                temp = "";
            }
            else {
                st.push(temp);
                temp = "";
            }
        }

        string ans;
        while (!st.empty()) {
            ans.insert(ans.begin(), st.top().begin(), st.top().end());
            ans.insert(ans.begin(), '/');
            st.pop();
        }
        if (ans.empty()) ans = "/";
        return ans;
    }
};