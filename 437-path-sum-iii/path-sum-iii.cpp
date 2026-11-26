class Solution {
public:
    int dfs(TreeNode* root, long long sum, int target){
        if(root == nullptr) return 0;

        sum += root->val;

        int ans = 0;

        if(sum == target){
            ans++;
        }

        ans += dfs(root->left, sum, target);
        ans += dfs(root->right, sum, target);

        return ans;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return 0;

        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int s = q.size();

            for(int i = 0; i < s; i++){
                TreeNode* temp = q.front();
                q.pop();

                ans += dfs(temp, 0, targetSum);

                if(temp->left != nullptr){
                    q.push(temp->left);
                }

                if(temp->right != nullptr){
                    q.push(temp->right);
                }
            }
        }

        return ans;
    }
};