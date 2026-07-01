class Node {
public:
    int key;
    int value;
    Node* next;

    Node(int k, int v) : key(k), value(v), next(nullptr) {}
};

class MyHashMap {
private:
    vector<Node*> hash;

public:
    MyHashMap() {
        hash.resize(1000);
        for (int i = 0; i < 1000; i++) {
            hash[i] = new Node(-1, -1);
        }
    }
    
    void put(int key, int value) {
        int bucket = key % 1000;
        Node* curr = hash[bucket];
        while (curr -> next && curr -> next -> key != key) curr = curr -> next;
        if (curr -> next) curr -> next -> value = value;
        else {
            Node* n = new Node(key, value);
            curr -> next = n;
        }
    }
    
    int get(int key) {
        int bucket = key % 1000;
        Node* curr = hash[bucket];
        while (curr && curr -> key != key) curr = curr -> next;
        if (curr) return curr -> value;
        else return -1;
    }
    
    void remove(int key) {
        int bucket = key % 1000;
        Node* curr = hash[bucket];
        while (curr -> next && curr -> next -> key != key) curr = curr -> next;
        if (curr -> next) {
            Node* temp = curr -> next;
            curr -> next = temp -> next;
            delete temp;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */