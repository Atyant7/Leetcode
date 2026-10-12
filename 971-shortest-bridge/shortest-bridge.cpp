class Solution {
public:
    void bfs(vector<vector<int>>& grid, int i, int j,
             vector<vector<int>>& vis,
             queue<pair<int, int>>& que) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({i, j});
        que.push({i, j});
        vis[i][j] = 1;

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int newr = row + dr[k];
                int newc = col + dc[k];

                if (newr < 0 || newr >= n ||
                    newc < 0 || newc >= m) {
                    continue;
                }

                if (grid[newr][newc] == 1 &&
                    vis[newr][newc] == 0) {

                    vis[newr][newc] = 1;
                    q.push({newr, newc});
                    que.push({newr, newc});
                }
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> que;

        // Find and mark only the first island
        bool found = false;

        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < m && !found; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    bfs(grid, i, j, vis, que);
                    found = true;
                }
            }
        }

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        int step = 0;

        // Expand BFS from the first island
        while (!que.empty()) {
            int sz = que.size();

            while (sz--) {
                auto [row, col] = que.front();
                que.pop();

                for (int k = 0; k < 4; k++) {
                    int newr = row + dr[k];
                    int newc = col + dc[k];

                    if (newr < 0 || newr >= n ||
                        newc < 0 || newc >= m) {
                        continue;
                    }

                    // Reached the second island
                    if (grid[newr][newc] == 1 &&
                        vis[newr][newc] == 0) {
                        return step;
                    }

                    // Skip already visited cells
                    if (vis[newr][newc] == 1) {
                        continue;
                    }

                    // Mark and enqueue water
                    vis[newr][newc] = 1;
                    que.push({newr, newc});
                }
            }

            step++;
        }

        return -1;
    }
};