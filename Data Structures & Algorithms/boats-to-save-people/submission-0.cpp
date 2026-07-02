class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int i = 0, j = n - 1;
        sort(people.begin(), people.end());

        int cnt = 0;
        while (i < j) {
            if (people[i] + people[j] <= limit) {
                i++;
                j--;
                cnt++;
            }
            else {
                j--;
                cnt++;
            }
        }
        if (i == j) cnt++;
        
        return cnt;
    }
};