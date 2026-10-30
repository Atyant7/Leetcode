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
    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = height(root->left);
        int right = height(root->right);
        return 1 + max(left, right);
    }
    int deepestLeavesSum(TreeNode* root) {
        int h = height(root);
        queue<TreeNode*> q;
        q.push(root);
        int n = 0;
        int ans = 0;
        while (!q.empty()) {
            int s = q.size();
            n++;
            for (int i = 0; i < s; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(n == h){
                    ans += temp->val;
                }
                if (temp->left != nullptr) {
                    q.push(temp->left);
                }
                if (temp->right != nullptr) {
                    q.push(temp->right);
                }
            }
        }
        return ans;
    }
};