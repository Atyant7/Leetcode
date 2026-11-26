class Solution {
public:
    int f1(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp) {
        int n = matrix.size();
        int m = matrix[0].size();

        if (i < 0 || j < 0 || j >= m) {
            return INT_MAX;
        }

        if (i == n - 1) {
            return matrix[i][j];
        }

        if(dp[i][j] != INT_MAX) return dp[i][j];

        int down = f1(matrix, i + 1, j, dp);
        int left = f1(matrix, i + 1, j - 1, dp);
        int right = f1(matrix, i + 1, j + 1, dp);

        return dp[i][j] = matrix[i][j] + min({down, left, right});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans2 = INT_MAX;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix.size(), INT_MAX));
        for (int i = 0; i < matrix.size(); i++) {
            ans2 = min(ans2, f1(matrix, 0, i, dp));
        }
        return ans2;
    }
};