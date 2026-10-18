class SolutionBFS {
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


// DFS
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c, int fish) {
        int rows = grid.size(), cols = grid[0].size();

        if(r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0) return fish;

        fish += grid[r][c];
        grid[r][c] = 0;

        fish = dfs(grid, r-1, c, fish);
        fish = dfs(grid, r, c+1, fish);
        fish = dfs(grid, r+1, c, fish);
        fish = dfs(grid, r, c-1, fish);

        return fish;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int maxFish = INT_MIN, rows = grid.size(), cols = grid[0].size();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] > 0) {
                    int fish = dfs(grid, i, j, 0);
                    maxFish = max(fish, maxFish);
                }
            }
        }

        return (maxFish == INT_MIN) ? 0 : maxFish;
    }
};