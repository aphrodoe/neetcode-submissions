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
    TreeNode* build(int prestart, int preend, int instart, int inend, unordered_map<int, int>& mp,
    vector<int>& preorder, vector<int>& inorder) {
        if (prestart > preend || instart > inend) return NULL;

        int r = preorder[prestart];
        TreeNode* root = new TreeNode(r);
        int ind = mp[r];
        root -> left = build(prestart + 1, prestart + ind - instart, instart, ind - 1, mp, preorder, inorder);
        root -> right = build(prestart + ind - instart + 1, preend, ind + 1, inend, mp, preorder, inorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;

        TreeNode* root = build(0, preorder.size() - 1, 0, inorder.size() - 1, mp, preorder, inorder);
        return root;
    }
};
