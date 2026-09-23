class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const long long MOD = 12345;
        int n = grid.size();
        int m = grid[0].size();
        vector<long long> prefix(n*m + 1, 1);
        vector<long long> suffix(n*m + 1, 1);
        vector<vector<int>> ans(n, vector<int>(m));
        for(int k = 0; k < n*m; k++){
            int i = k / m;
            int j = k % m;
            prefix[k+1] = (prefix[k] * grid[i][j]) % MOD;
        }
        for(int k = n*m - 1; k >= 0; k--){
            int i = k / m;
            int j = k % m;
            suffix[k] = (suffix[k+1] * grid[i][j]) % MOD;
        }
        for(int k = 0; k < n*m; k++){
            int i = k / m;
            int j = k % m;
            ans[i][j] = (suffix[k+1] * prefix[k]) % MOD;
        }

        return ans;
    }
};