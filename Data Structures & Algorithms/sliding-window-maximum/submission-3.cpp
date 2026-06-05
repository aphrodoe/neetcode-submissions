class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> max;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }
        max.push_back(pq.top().first);
        int l = 1;
        int r = k;
        while (r < nums.size()) {
            while (!pq.empty() && pq.top().second < l) pq.pop();
            pq.push({nums[r], r});
            max.push_back(pq.top().first);
            l++;
            r++;
        }
        return max;
        
    }
};
