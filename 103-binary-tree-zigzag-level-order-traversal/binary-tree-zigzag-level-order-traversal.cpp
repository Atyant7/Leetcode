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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> Q;
        Q.push(root);
        int level = 0;
        while(!Q.empty()){
            int level_size = Q.size();
            vector<int> curr_level;
            for(int i = 0 ; i < level_size ; i++){
                TreeNode* temp = Q.front();
                Q.pop();
                curr_level.push_back(temp->val);
                if(temp->left != nullptr){
                    Q.push(temp->left);
                }
                if(temp->right != nullptr){
                    Q.push(temp->right);
                }
            }
            ans.push_back(curr_level);
        }
        for(int i = 0 ; i < ans.size() ; i++){
            if(i%2 != 0){
                reverse(ans[i].begin() , ans[i].end());
            }
        }
        return ans;
    }
};