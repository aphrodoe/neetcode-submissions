class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gc = 0, mind = 0, g = 0, c = 0, n = gas.size();
        for (int i = 0; i < n; i++) {
            g += gas[i];
            c += cost[i];
            gc += gas[i] - cost[i];
            if (gc < 0) {
                gc = 0;
                mind = i + 1;
            }
        }
        return (g - c < 0) ? -1 : mind;
    }
};
