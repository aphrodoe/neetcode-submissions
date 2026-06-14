class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int i = 0; i < stones.size(); i++) pq.push(stones[i]);

        while (!pq.empty() && pq.size() != 1) {
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();
            int n = abs(s1 - s2);
            if (n != 0) pq.push(n);
        }

        if (pq.empty()) return 0;
        return pq.top();
    }
};
