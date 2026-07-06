class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int carry = 0;
        int p1 = a.size() - 1, p2 = b.size() - 1;
        while (p1 >= 0 && p2 >= 0) {
            int n1 = a[p1] - '0', n2 = b[p2] - '0';
            int sum = n1 + n2 + carry;
            if (sum == 0) {
                ans.push_back('0');
                carry = 0;
            }
            else if (sum == 1) {
                ans.push_back('1');
                carry = 0;
            }
            else if (sum == 2) {
                ans.push_back('0');
                carry = 1;
            }
            else {
                ans.push_back('1');
                carry = 1;
            }
            p1--;
            p2--;
        }

        while (p1 >= 0) {
            int n1 = a[p1] - '0';
            int sum = n1 + carry;
            if (sum == 0) {
                ans.push_back('0');
                carry = 0;
            }
            else if (sum == 1) {
                ans.push_back('1');
                carry = 0;
            }
            else {
                ans.push_back('0');
                carry = 1;
            }
            p1--;
        }

        while (p2 >= 0) {
            int n2 = b[p2] - '0';
            int sum = n2 + carry;
            if (sum == 0) {
                ans.push_back('0');
                carry = 0;
            }
            else if (sum == 1) {
                ans.push_back('1');
                carry = 0;
            }
            else {
                ans.push_back('0');
                carry = 1;
            }
            p2--;
        }

        if (carry == 1) ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};