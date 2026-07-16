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
    TreeNode* getSuc(TreeNode* root) {
        TreeNode* temp = root -> right;
        while (temp -> left) temp = temp -> left;
        return temp;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        if (root -> val > key) {
            root -> left = deleteNode(root -> left, key);
        }
        else if (root -> val < key) {
            root -> right = deleteNode(root -> right, key);
        }
        else {
            if (root -> right == nullptr) {
                TreeNode* temp = root -> left;
                delete root;
                return temp;
            }
            else if (root -> left == nullptr) {
                TreeNode* temp = root -> right;
                delete root;
                return temp;
            }
            TreeNode* suc = getSuc(root);
            root -> val = suc -> val;
            root -> right = deleteNode(root -> right, suc -> val);
        }
        return root;
    }
};