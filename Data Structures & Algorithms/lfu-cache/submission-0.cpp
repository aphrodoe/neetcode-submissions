class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int k, int v) : key(k), val(v), next(NULL), prev(NULL) {}
};

class LFUCache {
    unordered_map<int, pair<int, Node*>> mp; // key frequency node
    unordered_map<int, pair<Node*, Node*>> freq; // frequency head tail
    int cap;
    int size;
    int minf;

public:
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
        minf = 1;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        auto it = mp[key];
        int f = it.first;
        Node* n = it.second;
        Node* p = n -> prev;
        Node* nt = n -> next;
        p -> next = nt;
        nt -> prev = p;
        auto itf = freq[f];
        if (itf.first -> next == itf.second && minf == f) minf++;
        if (freq.find(f + 1) == freq.end()) {
            Node* h = new Node(-1, -1);
            Node* t = new Node(-1, -1);
            h -> next = n;
            n -> prev = h;
            n -> next = t;
            t -> prev = n;
            freq[f + 1] = {h, t};
            mp[key] = {f + 1, n};
        }
        else {
            auto it = freq[f + 1];
            Node* h = it.first;
            Node* temp = h -> next;
            h -> next = n;
            n -> prev = h;
            n -> next = temp;
            temp -> prev = n;
            mp[key] = {f + 1, n};
        }  
        return mp[key].second -> val;
    }
    
    void put(int key, int value) {
        if (mp.find(key) == mp.end()) {
            Node* n = new Node(key, value);
            if (size != cap) {
                minf = 1;
                if (freq.find(1) == freq.end()) {
                    Node* h = new Node(-1, -1);
                    Node* t = new Node(-1, -1);
                    h -> next = n;
                    n -> prev = h;
                    n -> next = t;
                    t -> prev = n;
                    freq[1] = {h, t};
                    mp[key] = {1, n};
                    size++;
                }
                else {
                    Node* h = freq[1].first;
                    Node* temp = h -> next;
                    h -> next = n;
                    n -> prev = h;
                    n -> next = temp;
                    temp -> prev = n;
                    mp[key] = {1, n};
                    size++;
                }
            }
            else {
                Node* t = freq[minf].second;
                Node* d = t -> prev;
                Node* p = d -> prev;
                p -> next = t;
                t -> prev = p;
                mp.erase(d -> key);
                delete d;

                minf = 1;
                Node* h = freq[1].first;
                Node* temp = h -> next;
                h -> next = n;
                n -> prev = h;
                n -> next = temp;
                temp -> prev = n;
                mp[key] = {1, n};
            }
        }
        else {
            auto it = mp[key];
            int f = it.first;
            Node* n = it.second;
            Node* p = n -> prev;
            Node* nt = n -> next;
            p -> next = nt;
            nt -> prev = p;
            n -> val = value;
            auto itf = freq[f];
            if (itf.first -> next == itf.second && minf == f) minf++;
            if (freq.find(f + 1) == freq.end()) {
                Node* h = new Node(-1, -1);
                Node* t = new Node(-1, -1);
                h -> next = n;
                n -> prev = h;
                n -> next = t;
                t -> prev = n;
                freq[f + 1] = {h, t};
                mp[key] = {f + 1, n};
            }
            else {
                auto it = freq[f + 1];
                Node* h = it.first;
                Node* temp = h -> next;
                h -> next = n;
                n -> prev = h;
                n -> next = temp;
                temp -> prev = n;
                mp[key] = {f + 1, n};
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */