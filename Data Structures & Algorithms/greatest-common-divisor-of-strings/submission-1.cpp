class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.size(), len2 = str2.size(), len2c = str2.size();
        if (len1 < len2) return gcdOfStrings(str2, str1);

        int div = 2;
        while (len2c > 0) {
            if (len1 % len2c != 0) {
                len2c = len2 / div;
                div++;
                continue;
            }
            int rep = len1 / len2c;
            string reps = str2.substr(0, len2c);
            string temp1 = "";
            string temp2 = "";
            for (int i = 0; i < rep; i++) temp1 += reps;
            for (int i = 0; i < div - 1; i++) temp2 += reps;
            if (temp1 == str1 && temp2 == str2) break; 
            len2c = len2 / div;
            div++;
        }

        return str2.substr(0, len2c);
    }
};