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
    int msum(TreeNode* root, int& m) {
        if (root == nullptr) return 0;
        int mpl = max(0, msum(root -> left, m));
        int mpr = max(0, msum(root -> right, m));
        m = max(m, root -> val + mpl + mpr);

        return root -> val + max(mpl, mpr);
    }

    int maxPathSum(TreeNode* root) {
        int m = INT_MIN;
        msum(root, m);

        return m;
    }
};
