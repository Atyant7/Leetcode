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
    void dfs(TreeNode* root, vector<string>& v, string s){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr){
            v.push_back(s+(char(97+root->val)));
            return;
        }
        dfs(root->left, v, s+(char(97+root->val)));
        dfs(root->right, v, s+(char(97+root->val)));
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<string> v;
        char ch = 97+root->val;
        dfs(root, v, "");
        for(int i = 0; i < v.size(); i++){
            reverse(v[i].begin(), v[i].end());
        }
        sort(v.begin(), v.end());
        return v[0];
    }
};