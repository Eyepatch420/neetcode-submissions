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
   int maxSum = INT_MIN;
    int dfs(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        left = max(0,left);
        right = max(0,right);
        int currentPath = left + root->val + right;
        maxSum = max(maxSum, currentPath);
        return root->val + max(left, right);
        
    }
    int maxPathSum(TreeNode* root) {
        if(root == nullptr) return 0;
        dfs(root);
        return maxSum;

    }
};
