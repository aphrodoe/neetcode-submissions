class FreqStack {
public:
    int i;
    unordered_map<int, stack<int>> ind; // element -> indices where it appears
    priority_queue<pair<int, pair<int, int>>> freq; // frequency, last index, element

    FreqStack() {
        i = 0;
    }
    
    void push(int val) {
        ind[val].push(i);
        int f = ind[val].size();
        freq.push({f, {i, val}});
        i++;
    }
    
    int pop() {
        auto it = freq.top();
        freq.pop();
        int el = it.second.second;
        ind[el].pop();
        return el;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */