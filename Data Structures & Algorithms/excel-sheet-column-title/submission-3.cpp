class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while (columnNumber > 0) {
            int dig = columnNumber % 26;
            columnNumber /= 26;
            if (dig == 0) {
                ans.push_back('Z');
                columnNumber--;
                continue;
            }
            char c = 'A' + dig - 1;
            ans.push_back(c);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};