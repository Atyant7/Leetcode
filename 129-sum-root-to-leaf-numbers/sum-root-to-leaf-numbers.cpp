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
    int sum = 0;
    void sum_left_right(TreeNode* root, int n){
        if(root == NULL) return;
        n = n*10 + root->val;
        if(root->left == NULL && root -> right == NULL) {
            sum += n;
            return;
        }
        sum_left_right(root->left, n);
        sum_left_right(root->right, n);
    }
    int sumNumbers(TreeNode* root) {
        sum_left_right(root, 0);
        return sum;
    }
};