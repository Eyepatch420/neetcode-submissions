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
   
    void dfs(TreeNode* root, int& count, int maxNode = INT_MIN) {
        if (root == nullptr) return;
        if (root->val >= maxNode) count++;
        maxNode = max(root->val, maxNode);

        dfs(root->left, count, maxNode);
        dfs(root->right, count, maxNode);
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        if (root == nullptr) return 0;
        dfs(root, count);
        return count;
    }
};
