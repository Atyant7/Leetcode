class Solution {
public:
    int dfs(vector<int>& coins, int amount, int i, vector<vector<int>>& vis) {
        // Base cases
        if (amount == 0)
            return 0;
        if (amount < 0 || i == coins.size())
            return INT_MAX;
        if(vis[i][amount] != -1) return vis[i][amount];

        // Choice 1: Current coin choose karo
        int take = dfs(coins, amount - coins[i], i, vis);

        // Choice 2: Current coin skip karo
        int skip = dfs(coins, amount, i + 1, vis);

        if (take != INT_MAX)
            take++;

        return vis[i][amount] = min(take, skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> vis(coins.size(), vector<int>(amount+1, -1));
        int ans = dfs(coins, amount, 0, vis);

        return ans == INT_MAX ? -1 : ans;
    }
};