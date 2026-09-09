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
    vector<int> findMode(TreeNode* root) {
        if(root == nullptr) return {0};
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
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
        map<int, int> mp;
        for(auto a : v){
            mp[a]++;
        }
        if(mp.size() == v.size()) return v;
        v.clear();
        int mode = INT_MIN;
        for(auto m : mp){
            mode = max(mode, m.second);
        }
        for(auto m : mp){
            if(m.second == mode){
                v.push_back(m.first);
            }
        }

        return v;
    }
};