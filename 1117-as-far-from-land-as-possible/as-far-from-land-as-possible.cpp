class Solution1 {
public:
    int bfs(vector<vector<int>>& grid, int i, int j){
        int n = grid.size();
        queue<vector<int>> q;
        q.push({i, j, 0});
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vis[i][j] = true;
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        while(!q.empty()){
            vector<int> temp = q.front();
            q.pop();

            int row = temp[0];
            int col = temp[1];
            int dis = temp[2];

            for(int k = 0; k < 4; k++){
                int nr = row + dr[k];
                int nc = col + dc[k];
                
                if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;

                if(grid[nr][nc] == 1){
                    return dis + 1;
                }

                if(grid[nr][nc] == 0){
                    q.push({nr, nc, dis+1});
                    vis[nr][nc] = true;
                }
            } 
        }
        return -1;
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = INT_MIN;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    int temp = bfs(grid, i, j);
                    ans = max(temp, ans);
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        if (q.empty() || q.size() == n * n)
            return -1;

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        int dist = -1;

        while (!q.empty()) {
            int sz = q.size();
            dist++;

            while (sz--) {
                auto [row, col] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nr = row + dr[k];
                    int nc = col + dc[k];

                    if (nr < 0 || nr >= n ||
                        nc < 0 || nc >= n ||
                        grid[nr][nc] != 0)
                        continue;

                    grid[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        return dist;
    }
};