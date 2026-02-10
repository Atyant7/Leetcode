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
    bool dfs(TreeNode* node){
        if(node == nullptr)
            return false;
        bool leftStatus = dfs(node->left);
        bool rightStatus = dfs(node->right);

        if(leftStatus == false){
            node->left = NULL;
        }
        if (rightStatus == false){
            node->right = NULL;
        }
        return (leftStatus || rightStatus || node->val == 1);
    }
    TreeNode* pruneTree(TreeNode* root) {
        return dfs(root)? root : nullptr;
    }
};