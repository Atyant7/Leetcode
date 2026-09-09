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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v;
        queue<TreeNode*> q;
        if (root1 == nullptr) {
            q.push(root2);
            while (!q.empty()) {
                TreeNode* temp = q.front();
                q.pop();
                v.push_back(temp->val);
                if (temp->left != nullptr) {
                    q.push(temp->left);
                }
                if (temp->right != nullptr) {
                    q.push(temp->right);
                }
            }
            sort(v.begin(), v.end());
            return v;
        }
        if (root2 == nullptr) {
            q.push(root1);
            while (!q.empty()) {
                TreeNode* temp = q.front();
                q.pop();
                v.push_back(temp->val);
                if (temp->left != nullptr) {
                    q.push(temp->left);
                }
                if (temp->right != nullptr) {
                    q.push(temp->right);
                }
            }
            sort(v.begin(), v.end());
            return v;
        }
        q.push(root1);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            v.push_back(temp->val);
            if (temp->left != nullptr) {
                q.push(temp->left);
            }
            if (temp->right != nullptr) {
                q.push(temp->right);
            }
        }
        q.push(root2);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            v.push_back(temp->val);
            if (temp->left != nullptr) {
                q.push(temp->left);
            }
            if (temp->right != nullptr) {
                q.push(temp->right);
            }
        }
        sort(v.begin(), v.end());
        return v;
    }
};