class Solution {
public:
    bool dfs(TreeNode* root, ListNode* head, bool matched) {
        if(head == nullptr) return true;
        if(root == nullptr) return false;

        if(matched) {
            if(root->val != head->val) return false;

            return dfs(root->left, head->next, true) ||
                   dfs(root->right, head->next, true);
        }

        return dfs(root, head, true) ||
               dfs(root->left, head, false) ||
               dfs(root->right, head, false);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(root, head, false);
    }
};