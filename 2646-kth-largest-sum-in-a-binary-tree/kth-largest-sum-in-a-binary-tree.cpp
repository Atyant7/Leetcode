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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        priority_queue<long long> pq;
        while(!q.empty()){
            int s = q.size();
            long long ans = 0;
            for(int i = 0; i < s; i++){
                TreeNode* temp = q.front();
                q.pop();
                ans+=temp->val;
                if(temp->left != nullptr){
                    q.push(temp->left);
                }
                if(temp->right != nullptr){
                    q.push(temp->right);
                }
            }
            pq.push(ans);
        }
        if(pq.size() < k) return -1;
        for(int i = 0; i < k-1; i++){
            pq.pop();
        }
        return pq.top();
    }
};