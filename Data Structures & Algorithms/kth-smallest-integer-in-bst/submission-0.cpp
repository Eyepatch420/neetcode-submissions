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
    int ans = INT_MIN;

    void dfs(TreeNode* root, int k, int& count) {
        if (root == nullptr) return;
        dfs(root->left, k, count);
        count++;
        if (count == k) {
            ans = root->val;
            return;
        }

        dfs(root->right, k, count);
    }
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr) ans = 0;
        int count = 0;
        dfs(root, k, count);
        return ans;
    }
};
