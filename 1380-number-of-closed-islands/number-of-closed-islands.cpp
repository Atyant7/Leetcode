class Solution {
public:
    bool bfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis){
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        bool flag = true;

        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int row = temp.first;
            int col = temp.second;
            for(int i = 0; i < 4; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];
                if((grid[nr][nc] == 0 )&& (nr == 0 || nr == n - 1 || nc == 0 || nc == m - 1)){
                    flag = false;
                    continue;
                }
                if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if(grid[nr][nc] == 0 && !vis[nr][nc]){
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        // if(sum % k == 0) return true;
        return flag;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int cnt = 0;

        for(int i = 1; i < n-1; i++){
            for(int j = 1; j < m-1; j++){
                if(grid[i][j] == 0 && !vis[i][j]){
                    if(bfs(grid, i, j, vis)){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};