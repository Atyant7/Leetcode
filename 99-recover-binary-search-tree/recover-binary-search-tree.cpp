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
    vector<TreeNode*> v;

    void inorder(TreeNode* root) {
        if (root == nullptr)
            return;
        inorder(root->left);
        v.push_back(root);
        inorder(root->right);
    }

    int count = 2;

    void dfs(TreeNode* root, TreeNode* X, TreeNode* Y, int& count, int valX,
             int valY) {
        if (root == nullptr || count == 0)
            return;

        if (root == X) {
            root->val = valY;
            count--;
        } else if (root == Y) {
            root->val = valX;
            count--;
        }

        dfs(root->left, X, Y, count, valX, valY);
        dfs(root->right, X, Y, count, valX, valY);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        TreeNode* X = nullptr;
        TreeNode* Y = nullptr;
        int flag = 0;

        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i]->val > v[i + 1]->val && flag == 0) {
                Y = v[i];
                X = v[i + 1]; // FIRST inversion
                flag = 1;
            } else if (v[i]->val > v[i + 1]->val && flag == 1) {
                X = v[i + 1]; // SECOND inversion
                break;
            }
        }

        dfs(root, X, Y, count,X->val,Y->val);
    }
};