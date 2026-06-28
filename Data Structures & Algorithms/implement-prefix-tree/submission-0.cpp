class Node {
public:
    vector<Node*> ref;
    bool flag;

    Node() {
        ref.resize(26);
        flag = false;
    }
};

class PrefixTree {
public:
    Node* root;

    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        int n = word.size();
        Node* curr = root;
        for (int i = 0; i < n; i++) {
            int c = word[i] - 'a';
            if (curr -> ref[c] == nullptr) {
                curr -> ref[c] = new Node();
            }
            if (i == n - 1) curr -> ref[c] -> flag = true;
            curr = curr -> ref[c];
        }
    }
    
    bool search(string word) {
        int n = word.size();
        Node* curr = root;
        for (int i = 0; i < n; i++) {
            int c = word[i] - 'a';
            if (curr -> ref[c] == nullptr) return false;
            curr = curr -> ref[c];
        }
        return curr -> flag;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        Node* curr = root;
        for (int i = 0; i < n; i++) {
            int c = prefix[i] - 'a';
            if (curr -> ref[c] == nullptr) return false;
            curr = curr -> ref[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */