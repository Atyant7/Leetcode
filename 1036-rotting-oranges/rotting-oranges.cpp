class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans = -1;
        // int n_rotten = 0;
        int fresh = 0;
        int cnt = 0;
        vector<pair<int, int>> rotten;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    rotten.push_back({i, j});
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        queue<pair<int, int>> q;
        for(int i = 0; i < rotten.size(); i++){
            q.push(rotten[i]);
            vis[rotten[i].first][rotten[i].second] = true;
        }
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()){
            int size = q.size();
            ans++;
            for(int i = 0; i < size; i++){
                auto a = q.front();
                q.pop();
                int row = a.first;
                int col = a.second;
                for(int i = 0; i < 4; i++){
                    int nr = row + dr[i];
                    int nc = col + dc[i];

                    if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    if(grid[nr][nc] == 0) continue;

                    if(grid[nr][nc] == 1 && !vis[nr][nc]){
                        q.push({nr, nc});
                        cnt++;
                        vis[nr][nc] = true;
                    }
                }
            }

        }
        if(fresh - cnt > 0) return -1;

        return ans == -1 ? 0 : ans ;
    }
};