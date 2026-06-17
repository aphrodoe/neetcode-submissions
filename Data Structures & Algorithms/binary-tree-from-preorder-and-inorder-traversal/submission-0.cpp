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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if (n == 0) return NULL;

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) mp[inorder[i]] = i;

        int r = preorder[0];
        int ind = mp[r];
        vector<int> leftin;
        for (int i = 0; i < ind; i++) leftin.push_back(inorder[i]);
        vector<int> rightin;
        for (int i = ind + 1; i < inorder.size(); i++) rightin.push_back(inorder[i]);
        vector<int> leftpre;
        for (int i = 1; i <= leftin.size(); i++) leftpre.push_back(preorder[i]);
        vector<int> rightpre;
        for (int i = 1 + leftin.size(); i < preorder.size(); i++) rightpre.push_back(preorder[i]);

        TreeNode* root = new TreeNode(r);
        root -> left = buildTree(leftpre, leftin);
        root -> right = buildTree(rightpre, rightin);

        return root;
    }
};