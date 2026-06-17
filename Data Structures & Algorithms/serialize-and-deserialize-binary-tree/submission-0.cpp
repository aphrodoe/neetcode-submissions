/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:
    void preorder(TreeNode* root, vector<int>& pre) {
        if (root == nullptr) {
            pre.push_back(INT_MIN);
            return;
        }
        pre.push_back(root -> val);
        preorder(root -> left, pre);
        preorder(root -> right, pre);
    }

    TreeNode* build(vector<int>& pre, int& ind) {
        if (pre[ind] == INT_MIN) {
            ind++;
            return NULL;
        }

        TreeNode* root = new TreeNode(pre[ind++]);
        root -> left = build(pre, ind);
        root -> right = build(pre, ind);

        return root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<int> pre;
        preorder(root, pre);
        string s;
        for (int& i: pre) s += to_string(i) + "#";
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> pre;
        string s;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == '#') {
                pre.push_back(stoi(s));
                s = "";
                continue;
            }
            s.push_back(data[i]);
        }
        int n = 0;
        TreeNode* root = build(pre, n);
        return root;

    }
};
