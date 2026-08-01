class Node {
public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int n) {
        data = n;
        next = NULL;
        prev = NULL;
    }
};

class MyCircularQueue {
    Node* head;
    Node* tail;
    int size;
    int cap;

public:
    MyCircularQueue(int k) {
        size = 0;
        cap = k;
        head = new Node(-1);
        tail = new Node(-1);
        head -> next = tail;
        head -> prev = tail;
        tail -> prev = head;
        tail -> next = head;
    }
    
    bool enQueue(int value) {
        if (size == cap) return false;
        Node* n = new Node(value);
        Node* temp = tail -> prev;
        tail -> prev = n;
        n -> next = tail;
        n -> prev = temp;
        temp -> next = n;
        size++;
        return true;
    }
    
    bool deQueue() {
        if (size == 0) return false;
        Node* n = head -> next -> next;
        Node* temp = head -> next;
        head -> next = n;
        n -> prev = head;
        delete temp;
        size--;
        return true;
    }
    
    int Front() {
        if (size == 0) return -1;
        return head -> next -> data;
    }
    
    int Rear() {
        if (size == 0) return -1;
        return tail -> prev -> data;
    }
    
    bool isEmpty() {
        return (size == 0);
    }
    
    bool isFull() {
        return (size == cap);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */