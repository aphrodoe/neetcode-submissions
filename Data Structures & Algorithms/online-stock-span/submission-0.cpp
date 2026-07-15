class StockSpanner {
public:
    stack<int> st;
    vector<int> p;
    int curr;

    StockSpanner() {
        curr = 0;
    }
    
    int next(int price) {
        p.push_back(price);
        while (!st.empty() && p[st.top()] <= price) st.pop();
        int pge = (st.empty()) ? -1 : st.top();
        int ans = curr - pge;
        st.push(curr++);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */