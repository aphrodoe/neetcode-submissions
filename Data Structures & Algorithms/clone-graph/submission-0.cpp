/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return node;
        Node* root = new Node(node -> val);
        unordered_map<Node*, Node*> mp;
        unordered_map<Node*, int> vis;
        mp[node] = root;

        queue<Node*> q;
        q.push(node);
        vis[node] = 1;

        while (!q.empty()) {
            Node* n = q.front();
            q.pop();
            Node* newn = mp[n];
            for (Node* neigh : n -> neighbors) {
                if (mp.find(neigh) == mp.end()) {
                    Node* newneigh = new Node(neigh -> val);
                    mp[neigh] = newneigh;
                }
                newn -> neighbors.push_back(mp[neigh]);
                if (vis.find(neigh) == vis.end()) {
                    vis[neigh] = 1;
                    q.push(neigh);
                }
            }
        }

        return root;
    }
};
