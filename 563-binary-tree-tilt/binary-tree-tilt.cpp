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
    int total_tilt = 0;
    int dfs(TreeNode* root){
        if(root == nullptr) return 0;
        int L = dfs(root->left);
        int R = dfs(root->right);
        total_tilt += abs(L-R);
        return (L+R+root->val) ;
    }
    int findTilt(TreeNode* root) {
        dfs(root);
        return total_tilt;
    }
};