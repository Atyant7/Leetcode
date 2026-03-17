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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> ans;
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            int level_size = Q.size();
            for (int i = 0; i < level_size; i++) {
                TreeNode* temp = Q.front();
                if (temp->left != nullptr) {
                    Q.push(temp->left);
                }
                if (temp->right != nullptr) {
                    Q.push(temp->right);
                }
                if (i == level_size - 1) {
                    ans.push_back(temp->val);
                }
                Q.pop();
            }
        }
        return ans;
    }
};