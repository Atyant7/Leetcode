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
    void dfs(TreeNode* root, vector<int>& v){
        if(root == nullptr) return;
        v.push_back(root->val);
        dfs(root->left, v);
        dfs(root->right, v);
    }
    int findSecondMinimumValue(TreeNode* root) {
        vector<int> v;
        dfs(root, v);
        sort(v.begin(), v.end());
        set<int> s;
        for(int i = 0 ; i < int(v.size()) ;  i++){
            s.insert(v[i]);
            if(s.size() == 2){
                return v[i];
            }
        }
        return -1;
    }
};