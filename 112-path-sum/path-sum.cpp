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
    bool dfs(TreeNode* root, int t){
        if(root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr) {
            return t == root->val;
        }
        return dfs(root->left, t - root->val) || dfs(root->right, t - root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        // if(root == nullptr || targetSum == 0) return false;
        // if(root->val == targetSum && (root->left == nullptr && root->right == nullptr)){
        //     return true;
        // }
        // if(root -> val == targetSum) return false;
        return dfs(root, targetSum);
    }
};