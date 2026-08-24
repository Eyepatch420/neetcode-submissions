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

class Codec {
   public:
    void dfs(TreeNode* root, string& result) {
        if (root == nullptr) {
            result += "#,";
            return;
        }

        result += to_string(root->val) + ",";
        dfs(root->left, result);
        dfs(root->right, result);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        dfs(root, result);
        return result;
    }

    TreeNode* build(string& data, int& index){
        int comma = data.find(',',index);
        string value = data.substr(index, comma - index);
        index = comma + 1;
        if(value == "#"){
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(value));
        root->left = build(data,index);
        root->right = build(data,index);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return build(data, index);
        
    }
};
