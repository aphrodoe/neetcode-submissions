/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool path(TreeNode* root, TreeNode* node, vector<TreeNode*>& p) {
        if (root == nullptr) return false;

        p.push_back(root);
        if (root -> val == node -> val) return true;

        if (path(root -> left, node, p)) return true;
        if (path(root -> right, node, p)) return true;
        p.pop_back();

        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p1;
        vector<TreeNode*> p2;

        path(root, p, p1);
        path(root, q, p2);

        TreeNode* lc = root;
        int n = min(p1.size(), p2.size());
        for (int i = 0; i < n; i++) {
            if (p1[i] -> val == p2[i] -> val) lc = p1[i];
        }

        return lc;

    }
};