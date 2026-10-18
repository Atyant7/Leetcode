class Solution {
public:
    int bfs(vector<vector<int>>& grid, int i, int j,
            vector<vector<bool>>& vis) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        q.push({i, j});
        vis[i][j] = true;
        int ans = grid[i][j];

        while (!q.empty()) {
            auto a = q.front();
            q.pop();
            int row = a.first;
            int col = a.second;
            for (int i = 0; i < 4; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m)
                    continue;

                if (grid[nrow][ncol] == 0 || vis[nrow][ncol])
                    continue;

                ans += grid[nrow][ncol];
                vis[nrow][ncol] = true;
                q.push({nrow, ncol});
            }
        }
        return ans;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j] > 0 && !vis[i][j]){
                    int temp = bfs(grid, i, j, vis);
                    ans = max(ans, temp);
                }
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }
};