/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int h = 0;
    TreeNode* ans = nullptr;
    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return 1 + max(leftHeight, rightHeight);
    }
    bool LC(TreeNode* root, int level){
        
        if((root == nullptr) && (level < h)){
            return false;
        }
        if((root == nullptr) && (level >= h)){
            return true;
        }
        
        bool l = LC(root->left, level+1);
        bool r = LC(root->right, level+1);

        if(l && r){
            ans = root;
        }
        
        return l || r;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root == nullptr) return root;
        h = height(root);
        LC(root, 0);
        return ans;
    }
};