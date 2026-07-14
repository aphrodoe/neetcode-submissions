class MyQueue {
public:
    stack<int> st;

    MyQueue() {
        
    }
    
    void push(int x) {
        vector<int> temp;
        while (!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }
        st.push(x);
        for (int i = temp.size() - 1; i >= 0; i--) st.push(temp[i]);
    }
    
    int pop() {
        int tp = st.top();
        st.pop();
        return tp;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */