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
    int dfs(TreeNode* node,int &maxi){
        if(node == nullptr){
            return 0;
        }
        int leftStatus = dfs(node->left,maxi);
        int rightStatus = dfs(node->right,maxi);
        maxi = max(leftStatus + rightStatus , maxi);
        return max(leftStatus , rightStatus) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        dfs(root , maxi);
        return maxi;
    }
};