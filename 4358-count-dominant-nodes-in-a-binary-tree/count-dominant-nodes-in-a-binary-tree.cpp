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
    int dfs(TreeNode* root, int & ans){
        if(root == nullptr) return INT_MIN;
        if(root->left == nullptr && root->right == nullptr){
            ans++;
            return root->val;
        }
        int left = dfs(root->left, ans);
        int right = dfs(root->right, ans);
        if(root->val >= max(left, right)){
            ans++;
        }
        return max(left, max(root->val, right));
    }
    int countDominantNodes(TreeNode* root) {
        int ans = 0;
        int res = dfs(root, ans);
        return ans;
    }
};