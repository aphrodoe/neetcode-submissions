class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        int n = speed.size();

        for (int i = 0; i < n; i++) cars.push_back({position[i], speed[i]});

        sort(cars.rbegin(), cars.rend());

        stack<double> st;
        for (int i = 0; i < n; i++) {
            double time = ((double)target - cars[i].first) / cars[i].second;
            if (st.empty() || time > st.top()) st.push(time);
        }

        return st.size();
    }
};
