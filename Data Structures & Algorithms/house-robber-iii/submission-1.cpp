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
    int money(TreeNode* root, unordered_map<TreeNode*, int>& mp) {
        if (root == NULL) return 0;
        if (mp.find(root) != mp.end()) return mp[root];
        int left = money(root -> left, mp), right = money(root -> right, mp);
        int gc1 = (root -> left) ? money(root -> left -> left, mp) : 0;
        int gc2 = (root -> left) ? money(root -> left -> right, mp) : 0;
        int gc3 = (root -> right) ? money(root -> right -> left, mp) : 0;
        int gc4 = (root -> right) ? money(root -> right -> right, mp) : 0;
        int pick = root -> val + gc1 + gc2 + gc3 + gc4;
        int notpick = left + right;
        return mp[root] = max(pick, notpick);
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> mp;
        return money(root, mp);
    }
};