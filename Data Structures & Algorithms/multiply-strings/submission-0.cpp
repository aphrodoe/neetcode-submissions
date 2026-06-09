class Solution {
public:
    string sum(string num1, string num2) {
        string s;
        int n = num1.size(), m = num2.size();
        if (n < m) return sum(num2, num1);
        int i = n - 1, j = m - 1, c = 0;

        while (i >= 0 && j >= 0) {
            int n1 = num1[i] - '0';
            int n2 = num2[j] - '0';
            int sum = n1 + n2 + c;
            if (sum < 10) {
                s.push_back(sum + '0');
                c = 0;
            }
            else {
                s.push_back((sum % 10) + '0');
                c = sum / 10;
            }
            i--;
            j--;
        }

        while (i >= 0) {
            int n1 = num1[i] - '0';
            int sum = n1 + c;
            if (sum < 10) {
                s.push_back(sum + '0');
                c = 0;
            }
            else {
                s.push_back((sum % 10) + '0');
                c = sum / 10;
            }
            i--; 
        }
        
        if (c > 0) s.push_back(c + '0');
        cout << s << endl;
        reverse(s.begin(), s.end());

        return s;
    }

    string multiply(string num1, string num2) {
        string m = "0";
        for (int i = num2.size() - 1; i >= 0; i--){
            string s1 = "0";
            for (int j = 0; j < num2[i] - '0'; j++) {
                s1 = sum(s1, num1);
            }
            for (int j = 0; j < num2.size() - 1 - i; j++) s1.push_back('0');
            m = sum(m, s1);
        }
        return m;
    }
};
