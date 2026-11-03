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
    bool isEvenOddTree(TreeNode* root) {
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int> v;
            for(int i = 0; i < s; i++){
                if(level % 2 == 0){
                    TreeNode* temp = q.front();
                    q.pop();
                    if(temp->val % 2 == 0){
                        return false;
                    }
                    v.push_back(temp->val);
                    if(temp->left != nullptr){
                        q.push(temp->left);
                    }
                    if(temp->right != nullptr){
                        q.push(temp->right);
                    }
                }else{
                    TreeNode* temp = q.front();
                    q.pop();
                    if(temp->val % 2 != 0){
                        return false;
                    }
                    v.push_back(temp->val);
                    if(temp->left != nullptr){
                        q.push(temp->left);
                    }
                    if(temp->right != nullptr){
                        q.push(temp->right);
                    }
                }

            }
            if(level % 2 == 0){
                for(int j = 1; j < v.size(); j++){
                    if(v[j] <= v[j-1]){
                        return false;
                    }
                }
            }else{
                for(int j = 1; j < v.size(); j++){
                    if(v[j] >= v[j-1]){
                        return false;
                    }
                }
            }
            level++;
        }
        return true;
    }
};