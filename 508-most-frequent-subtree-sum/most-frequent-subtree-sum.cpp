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
    int add(TreeNode* root, map<int, int>& mp){
        if(root == nullptr) return 0;
        // if(root->left == nullptr && root->right == nullptr) return root->val;
        int left = root->val + add(root->left, mp) + add(root->right, mp);
        mp[left]++;
        return left;
        
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> v;
        map<int, int> mp;
        int ok = add(root, mp);
        int ans = INT_MIN;
        for(auto a : mp){
            ans = max(ans, a.second);
        }
        for(auto a : mp){
            if(ans == a.second){
                v.push_back(a.first);
            }
        }
        return v;
        
    }
};