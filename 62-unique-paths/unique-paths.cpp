class Solution {
public:

    int Paths(int row, int col, int m, int n, vector<vector<int>>& dp){
        if(row >= m || col >= n) return 0;
        if(row == m-1 || col == n-1) return 1;
        if (dp[row][col] != -1) return dp[row][col];
        return dp[row][col] = Paths(row, col + 1, m, n, dp) + Paths(row+1, col, m, n, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n, -1));
        return Paths(0, 0, m, n, dp);
    }
};