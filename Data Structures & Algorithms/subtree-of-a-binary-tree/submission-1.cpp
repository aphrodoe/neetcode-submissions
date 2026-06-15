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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr) return (p == q);

        return ((p -> val == q -> val) && isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right));
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr || subRoot == nullptr) return (root == subRoot);

        if (root -> val == subRoot -> val && isSameTree(root, subRoot)) return true;
        else {
            if (isSubtree(root -> left, subRoot)) return true;
            if (isSubtree(root -> right, subRoot)) return true;
        }

        return false;
    }
};
