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
    int height(TreeNode* root){
        if (root == NULL || (root->left == NULL && root->right == NULL)) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) return 0;
        int leftAns = diameterOfBinaryTree(root->left);
        int rightAns = diameterOfBinaryTree(root->right);
        int mid = height(root->left) + height(root->right);
        if(root->left != NULL) mid++;
        if(root->right != NULL) mid++;
        int maxi = max(leftAns, max(rightAns, mid));
        return maxi;
        
    }
};
