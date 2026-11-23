class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[505][505][2];

    int dfs(vector<vector<int>>& grid, int i, int j, int d) {
        int m = grid.size();
        int n = grid[0].size();

        if(i >= m || j >= n) return 0;

        if(i == m-1 && j == n-1) return 1;

        if(dp[i][j][d] != -1)
            return dp[i][j][d];

        long long ans = 0;

        if(grid[i][j] == 0) {
            ans += dfs(grid, i+1, j, 0);
            ans += dfs(grid, i, j+1, 1);
        }
        else {
            if(d == 1) {
                ans += dfs(grid, i+1, j, 0);
            }
            else {
                ans += dfs(grid, i, j+1, 1);
            }
        }

        return dp[i][j][d] = ans % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp)); // initialise dp array with -1

        return dfs(grid, 0, 0, 1);
    }
};