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
    int maxLevelSum(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int level = 0;
        vector<pair<long long, int>> v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            level++;
            long long ok = 0;
            for(int i = 0; i < s; i++){
                TreeNode* temp = q.front();
                q.pop();
                ok += temp->val;
                if(temp->left != nullptr){
                    q.push(temp->left);
                }
                if(temp->right != nullptr){
                    q.push(temp->right);
                }
            }
            v.push_back({ok, level});
        }
        sort(v.begin(), v.end(), [](auto& a, auto& b){
            if(a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });
        return v[0].second;
    }
};