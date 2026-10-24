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
    int height(TreeNode* root){
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return 1;
        return 1 + max(height(root->left), height(root->right));
    }
    int findBottomLeftValue(TreeNode* root) {
        if(root == nullptr) return -1;
        int level = height(root);
        queue<TreeNode*> q;
        int cnt = 0;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            cnt++;
            for(int i = 0; i < s; i++){
                auto temp = q.front();
                q.pop();
                if(cnt == level){
                    if(temp->left != nullptr)
                        return temp->left->val;
                    return temp->val;
                }
                if(temp->left != nullptr)
                    q.push(temp->left);
                if(temp->right != nullptr)
                    q.push(temp->right);
            }
        }
        return -1;
    }
};