class MyStack {
public:
    queue<int> q;

    MyStack() {
        
    }
    
    void push(int x) {
        vector<int> temp;
        while (!q.empty()) {
            temp.push_back(q.front());
            q.pop();
        }
        q.push(x);
        for (int i = 0; i < temp.size(); i++) q.push(temp[i]);
    }
    
    int pop() {
        int t = q.front();
        q.pop();
        return t;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */