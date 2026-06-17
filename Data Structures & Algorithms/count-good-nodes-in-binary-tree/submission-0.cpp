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
    void dfs(TreeNode* root, priority_queue<int>& p, int& cnt) {
        if (root == nullptr) return;

        if (root -> val >= p.top()) {
            cnt++;
            p.push(root -> val);
        }
        
        dfs(root -> left, p, cnt);
        dfs(root -> right, p, cnt);

        if (root -> val == p.top()) p.pop();
    }

    int goodNodes(TreeNode* root) {
        priority_queue<int> path;
        path.push(INT_MIN);
        int cnt = 0;

        dfs(root, path, cnt);

        return cnt;
    }
};
