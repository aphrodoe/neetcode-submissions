class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int kth;

    KthLargest(int k, vector<int>& nums) {
        kth = k;

        if (k > nums.size()) {
            for (int i = 0; i < nums.size(); i++) pq.push(nums[i]);
        }

        else {
            for (int i = 0; i < k; i++) pq.push(nums[i]);

            for (int i = k; i < nums.size(); i++) {
                if (nums[i] > pq.top()) {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        if (pq.size() != kth) pq.push(val); 
        else if (val > pq.top()) {
            pq.pop();
            pq.push(val);
        }

        return pq.top();
    }

};
