class Node {
private:
    vector<Node*> links;
    bool flag;

public:
    Node() {
        links.resize(26, nullptr);
        flag = false;
    }

    ~Node() {
        for (Node* link : links) {
            delete link;
        }
    }

    bool hasLink(char c) {
        int ind = c - 'a';
        return (links[ind] != nullptr);
    }

    Node* getLink(char c) {
        int ind = c - 'a';
        return links[ind];
    }

    void addLink(char c, Node* n) {
        int ind = c - 'a';
        links[ind] = n;
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    ~Trie() {
        delete root;
    }

    void insert(string word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (!curr -> hasLink(word[i])) {
                Node* n = new Node();
                curr -> addLink(word[i], n);
            }
            curr = curr -> getLink(word[i]);
        }
        curr -> setEnd();
    }

    bool search(string word, Node* check) {
        Node* curr;
        if (check == nullptr) curr = root;
        else curr = check;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == '.') {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (curr -> hasLink(c)) {
                        if (search(word.substr(i + 1), curr -> getLink(c))) return true;
                    }
                }
                return false;
            }
            else if (!curr -> hasLink(word[i])) return false;
            else curr = curr -> getLink(word[i]);
        }
        return curr -> isEnd();
    }
};

class WordDictionary {
private:
    Trie* trie;

public:
    WordDictionary() {
        trie = new Trie();
    }
    
    void addWord(string word) {
        trie -> insert(word);
    }
    
    bool search(string word) {
        return trie -> search(word, nullptr);
    }
};
