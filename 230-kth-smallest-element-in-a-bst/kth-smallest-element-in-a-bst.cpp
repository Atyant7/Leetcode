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
    void dfs(TreeNode* root, int& c, int k, int& ans){
        if(root == nullptr) return;
        dfs(root->left, c, k, ans);
        c++;
        if(c == k){
            ans = root->val;
            return;
        }
        dfs(root->right, c, k, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int c = 0;
        dfs(root, c, k, ans);
        return ans;
    }
};