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
    bool inorder(TreeNode* root, int& cnt, int& ans, int& k) {
        if (root == NULL) return false;

        if (inorder(root -> left, cnt, ans, k)) return true;
        cnt++;
        if (cnt == k) {
            ans = root -> val;
            return true;
        }
        if (inorder(root -> right, cnt, ans, k)) return true;

        return false; 
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0, ans;
        inorder(root, cnt, ans, k);

        return ans; 
    }
};