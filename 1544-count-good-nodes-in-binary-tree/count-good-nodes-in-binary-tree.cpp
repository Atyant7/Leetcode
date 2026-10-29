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
    void helper(TreeNode* root, int ok, int& ans){
        if(root == nullptr) return;
        if(root->val >= ok){
            ans++;
            helper(root->left, root->val, ans);
            helper(root->right, root->val, ans);
        }
        else{
            helper(root->left, ok, ans);
            helper(root->right, ok, ans);
        }
    }
    int goodNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = 0;
        helper(root, root->val, ans);
        return ans;
    }
};