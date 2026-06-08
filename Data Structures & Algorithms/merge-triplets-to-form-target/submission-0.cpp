class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        vector<int> t = {INT_MIN, INT_MIN, INT_MIN};
        for (int i = 0; i < n; i++) {
            if (triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]) continue;
            t[0] = max(t[0], triplets[i][0]);
            t[1] = max(t[1], triplets[i][1]);
            t[2] = max(t[2], triplets[i][2]);
        }
        return (t == target);
    }
};
