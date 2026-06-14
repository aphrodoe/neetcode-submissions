class MedianFinder {
public:
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    int size;

    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        size++;
        if (pq1.empty()) {
            pq1.push(num);
            return;
        }
        else if (num > pq1.top()) pq2.push(num);
        else pq1.push(num);

        if ((int)pq1.size() - (int)pq2.size() > 1) {
            pq2.push(pq1.top());
            pq1.pop();
        }
        else if ((int)pq2.size() - (int)pq1.size() > 1) {
            pq1.push(pq2.top());
            pq2.pop();
        }
    }
    
    double findMedian() {
        if (size % 2 == 1) {
            if (pq1.size() > pq2.size()) return (double)pq1.top();
            else return (double)pq2.top();
        }
        else return ((double)pq1.top() + pq2.top()) / 2;
    }
};