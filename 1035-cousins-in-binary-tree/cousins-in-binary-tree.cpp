class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        pair<TreeNode*, int> p1 = {nullptr, -1};
        pair<TreeNode*, int> p2 = {nullptr, -1};

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while(!q.empty()){
            int s = q.size();

            for(int i = 0; i < s; i++){
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left != nullptr){
                    if(temp->left->val == x)
                        p1 = {temp, level};
                    else if(temp->left->val == y)
                        p2 = {temp, level};
                    else
                        q.push(temp->left);
                }

                if(temp->right != nullptr){
                    if(temp->right->val == x)
                        p1 = {temp, level};
                    else if(temp->right->val == y)
                        p2 = {temp, level};
                    else
                        q.push(temp->right);
                }
            }

            if(p1.first != nullptr || p2.first != nullptr)
                break;

            level++;
        }

        return p1.first != nullptr &&
               p2.first != nullptr &&
               p1.first != p2.first &&
               p1.second == p2.second;
    }
};