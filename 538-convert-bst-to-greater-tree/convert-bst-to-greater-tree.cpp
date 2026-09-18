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
    int binarySearch(vector<int> &v, int low, int high, int target){
        if(low > high) return -1;
        int mid = low + (high - low)/2;
        if(v[mid] == target) return mid;
        if(v[mid] < target) return binarySearch(v, mid + 1, high, target);
        return binarySearch(v, low, mid - 1, target);
    }
    int calSum(vector<int> &v, int i){
        int n = v.size();
        int sum = 0;
        for(int j = i; j < n; j++){
            sum+=v[j];
        }
        return sum;
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr) return root;
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            v.push_back(temp->val);
            if(temp->left != nullptr){
                q.push(temp->left);
            }
            if(temp->right != nullptr){
                q.push(temp->right);
            }
        }
        sort(v.begin(), v.end());
        int n = v.size();
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            int idx = binarySearch(v, 0, n, temp->val);
            int newVal = calSum(v, idx);
            temp->val = newVal;
            if(temp->left != nullptr){
                q.push(temp->left);
            }
            if(temp->right != nullptr){
                q.push(temp->right);
            }
        }
        return root;
    }
};