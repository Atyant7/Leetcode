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
    bool ok = true;
    int dekhtehai(TreeNode* root){
        if(root == NULL) return 0;
        int left = dekhtehai(root->left);
        int right = dekhtehai(root->right);
        if(abs(left - right) > 1) ok=false;
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        dekhtehai(root);
        return ok;

    }
};