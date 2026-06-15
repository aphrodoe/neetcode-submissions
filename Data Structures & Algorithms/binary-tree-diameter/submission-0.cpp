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

class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(height(root -> left), height(root -> right));
    }

    void maxd(TreeNode* root, int& m) {
        if (root == nullptr) return;

        int path = height(root -> left) + height(root -> right);
        m = max(m, path);

        maxd(root -> left, m);
        maxd(root -> right, m);
    } 

    int diameterOfBinaryTree(TreeNode* root) {
        int m = 0;
        maxd(root, m);

        return m;
    }
};
