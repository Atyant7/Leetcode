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
    int height(TreeNode* root) {
    if (root == nullptr) return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (root == nullptr ||
            (root->left == nullptr && root->right == nullptr))
            return root;

        unordered_map<TreeNode*, TreeNode*> mp;
        queue<TreeNode*> q;
        mp[root] = nullptr;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left != nullptr) {
                    mp[temp->left] = temp;
                    q.push(temp->left);
                }
                if (temp->right != nullptr) {
                    mp[temp->right] = temp;
                    q.push(temp->right);
                }
            }
        }
        int h = height(root);
        set<TreeNode*> st;
        int counter = 0;
        q.push(root);
        int cnt = 0;
        TreeNode* tr = nullptr;
        while (!q.empty()) {
            int s = q.size();
            counter++;
            for (int i = 0; i < s; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if (counter == h - 1) {
                    if (temp->left != nullptr) {
                        st.insert(temp);
                        q.push(temp->left);
                        cnt++;
                        tr = temp->left;
                    }
                    if (temp->right != nullptr) {
                        st.insert(temp);
                        q.push(temp->right);
                        cnt++;
                        tr = temp->right;
                    }
                } else {
                    if (temp->left != nullptr) {
                        q.push(temp->left);
                    }
                    if (temp->right != nullptr) {
                        q.push(temp->right);
                    }
                }
            }
        }
        if (cnt == 1)
            return tr;
        while (st.size() > 1) {
            set<TreeNode*> temp;

            for (auto a : st) {
                if (mp[a] != nullptr) {
                    temp.insert(mp[a]);
                }
            }

            st = temp;
        }

        return *st.begin();
    }
};