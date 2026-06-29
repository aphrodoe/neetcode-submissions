class Node {
private:
    vector<Node*> links;
    string word;

public:
    Node() {
        links.resize(26, nullptr);
    }

    ~Node() {
        for (Node* link : links) delete link;
        word.clear();
    }

    bool hasChar(char c) {
        int ind = c - 'a';
        return (links[ind] != nullptr);
    }

    Node* getChar(char c) {
        int ind = c - 'a';
        return links[ind];
    }

    void putChar(char c, Node* n) {
        int ind = c - 'a';
        links[ind] = n;
    }

    bool isEnd() {
        return (!word.empty());
    }

    string getWord() {
        return word;
    }

    void setWord(string s) {
        word = s;
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
    
    Node* getRoot() {
        return root;
    }

    void insert(string word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (!curr -> hasChar(word[i])) {
                Node* n = new Node();
                curr -> putChar(word[i], n);
            }
            curr = curr -> getChar(word[i]);
        }
        curr -> setWord(word);
    }
};

class Solution {
public:
    vector<int> drow = {-1, 1, 0, 0};
    vector<int> dcol = {0, 0, -1, 1};

    void dfs(vector<vector<char>>& board, int r, int c, Node* curr, unordered_set<string>& found) {
        if (!curr -> hasChar(board[r][c])) return;
        curr = curr -> getChar(board[r][c]);
        if (curr -> isEnd()) found.insert(curr -> getWord());

        int ch = board[r][c];
        board[r][c] = '.';
        for (int i = 0; i < 4; i++) {
            int nr = r + drow[i];
            int nc = c + dcol[i];
            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && board[nr][nc] != '.') {
                dfs(board, nr, nc, curr, found);
            }
        }
        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size(), m = board[0].size();
        Trie trie;
        for (string word : words) trie.insert(word);
        
        Node* curr = trie.getRoot();
        unordered_set<string> found;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (curr -> hasChar(board[i][j])) dfs(board, i, j, curr, found);
            }
        }

        vector<string> ans(found.begin(), found.end());
        return ans;
    }
};