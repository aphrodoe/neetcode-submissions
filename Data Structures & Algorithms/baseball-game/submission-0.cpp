class Solution {
public:
    int calPoints(vector<string>& operations) {
        int sum = 0;
        stack<string> st;
        for (int i = 0; i < operations.size(); i++) {
            string c = operations[i];
            if (c == "+") {
                string c1 = st.top();
                st.pop();
                string c2 = st.top();
                int n = stoi(c1) + stoi(c2);
                st.push(c1);
                st.push(to_string(n));
                sum += n;
            }
            else if (c == "D") {
                int n = stoi(st.top()) * 2;
                sum += n;
                st.push(to_string(n));
            }
            else if (c == "C")  {
                int n = stoi(st.top());
                sum -= n;
                st.pop();
            }
            else {
                int n = stoi(c);
                sum += n;
                st.push(c);
            }
        }
        return sum;
    }
};