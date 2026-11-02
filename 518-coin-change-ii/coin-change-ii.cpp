class Solution {
public:
    int dfs(vector<int>& coins, int amount, int i, vector<vector<int>>& vis) {
        if (amount == 0) return 1;
        if (amount < 0 || i == coins.size()) return 0;
        
        if(vis[i][amount] != -1) return vis[i][amount];

        int take = dfs(coins, amount - coins[i], i, vis);

        int skip = dfs(coins, amount, i + 1, vis);
        
        return vis[i][amount] = take + skip;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> vis(n+1, vector<int>(amount+1, -1));
        
        return dfs(coins, amount, 0, vis);
    }
};