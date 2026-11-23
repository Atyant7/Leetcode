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
    void dfs(TreeNode* root, vector<int>& r){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr){
            r.push_back(root->val);
            return;
        }
        dfs(root->left, r);
        dfs(root->right, r);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1;
        vector<int> r2;
        dfs(root1, r1);
        dfs(root2, r2);
        if(r1.size() != r2.size()) return false;
        for(int i = 0; i < r1.size(); i++){
            if(r1[i] != r2[i]) return false;
        }
        return true;
    }
};