class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> max;
        priority_queue<int> pq;
        for (int i = 0; i < k; i++) {
            pq.push(nums[i]);
        }
        max.push_back(pq.top());
        int l = 0;
        int r = k;
        while (r < nums.size()) {
            vector<int> temp;
            while (nums[l] != pq.top()) {
                temp.push_back(pq.top());
                pq.pop();
            }
            pq.pop();
            for (int i = 0; i < temp.size(); i++) pq.push(temp[i]);
            l++;
            pq.push(nums[r]);
            max.push_back(pq.top());
            r++;
        }
        return max;
        
    }
};
