class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            val = v;
            next = nullptr;
            prev = nullptr;
        }
    };

    unordered_map<int, Node*> mp;

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    int size = 0;

    Node* addtop(int k, int v) {
        Node* tp = new Node(k, v);
        Node* headn = head -> next;
        head -> next = tp;
        tp -> next = headn;
        headn -> prev = tp;
        tp -> prev = head;
        return tp;
    }

    void remove(Node* n) {
        Node* nodep = n -> prev;
        Node* noden = n -> next;
        nodep -> next = noden;
        noden -> prev = nodep;
        delete n;
    }

    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        else {
            Node* n = mp[key];
            int value = n -> val;
            mp[key] = addtop(key, value);
            remove(n);
            return value;
        }
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* n = mp[key];
            mp[key] = addtop(key, value);
            remove(n);
        }
        else if (size < cap) {
            Node* n = addtop(key, value);
            mp[key] = n;
            size++;
        }
        else {
            Node* lru = tail -> prev;
            mp.erase(lru -> key);
            remove(lru);
            Node* n = addtop(key, value);
            mp[key] = n;
        }
    }
};