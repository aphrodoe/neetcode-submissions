class Solution {
public:
    bool check(int i, int j, int k, string& s1, string& s2, string& s3) {
        if (i < 0 && j < 0 && k < 0) return true;
        if (i >= 0 && j >= 0 && s1[i] == s3[k] && s2[j] == s3[k]) {
            bool first = check(i - 1, j, k - 1, s1, s2, s3);
            bool second = check(i, j - 1, k - 1, s1, s2, s3);
            return (first | second);
        }
        else if (i >= 0 && s1[i] == s3[k]) return check(i - 1, j, k - 1, s1, s2, s3);
        else if (j >= 0 && s2[j] == s3[k]) return check(i, j - 1, k - 1, s1, s2, s3);
        else return false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n1 + n2 != n3) return false;
        return check(n1 - 1, n2 - 1, n3 - 1, s1, s2, s3);
    }
};
