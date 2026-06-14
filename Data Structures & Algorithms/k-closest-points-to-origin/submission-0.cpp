class Solution {
public:
    double dist(vector<int>& point) {
        return (sqrt(pow(point[0], 2) + pow(point[1], 2)));
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> pq;
        for (int i = 0; i < k; i++) pq.push({dist(points[i]), points[i]});

        for (int i = k; i < points.size(); i++) {
            if (dist(points[i]) < pq.top().first) {
                pq.pop();
                pq.push({dist(points[i]), points[i]});
            }
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
