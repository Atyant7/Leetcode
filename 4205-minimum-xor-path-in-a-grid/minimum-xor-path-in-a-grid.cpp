class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int xorr,
             vector<vector<vector<bool>>>& vis,
             int n, int m, int& ans) {

        xorr ^= grid[i][j];

        if (vis[i][j][xorr]) return;
        vis[i][j][xorr] = true;

        if (i == n - 1 && j == m - 1) {
            ans = min(ans, xorr);
            return;
        }

        if (j + 1 < m)
            dfs(grid, i, j + 1, xorr, vis, n, m, ans);

        if (i + 1 < n)
            dfs(grid, i + 1, j, xorr, vis, n, m, ans);
    }

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<vector<bool>>> vis(
            n, vector<vector<bool>>(m, vector<bool>(1024, false))
        );

        int ans = INT_MAX;
        dfs(grid, 0, 0, 0, vis, n, m, ans);

        return ans;
    }
};