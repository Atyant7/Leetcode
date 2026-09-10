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
    int bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        int n = 1;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            sum+=temp->val;
            if(temp->left != nullptr){
                q.push(temp->left);
                n++;
            }
            if(temp->right != nullptr){
                q.push(temp->right);
                n++;
            }
        }
        return sum/n;
    }
    int averageOfSubtree(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr) return 1;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            int ok = bfs(temp);
            if(ok == temp->val) ans++;
            if(temp->left != nullptr){
                q.push(temp->left);
            }
            if(temp->right != nullptr){
                q.push(temp->right);
            }
        }
        return ans;
    }
};