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
    vector<int> dfs(TreeNode* root){
        if(root == nullptr) return {0, 0};
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        int extra = root->val + left[0] + right[0] - 1;
        int move = abs(left[0]) + abs(right[0])
                  + left[1] + right[1];
        return {extra, move};
    }
    int distributeCoins(TreeNode* root) {
        vector<int> move = dfs(root);
        return move[1];
    }
};