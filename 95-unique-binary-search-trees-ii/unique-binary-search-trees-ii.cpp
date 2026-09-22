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
    vector<TreeNode*> helper(int start, int end){
        if(start > end){
            return {NULL};
        }
        // if(start == end){
        //     TreeNode* node = new TreeNode(start);
        //     return {node};
        // }
        vector<TreeNode*> ans;
        for(int i = start ; i <= end ; i++){
            vector<TreeNode*> left = helper(start, i-1);
            vector<TreeNode*> right = helper(i+1, end);
            for(auto left_subtree : left){
                for(auto right_subtree : right){
                    TreeNode* root = new TreeNode(i);
                    root->left = left_subtree;
                    root->right = right_subtree;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
};