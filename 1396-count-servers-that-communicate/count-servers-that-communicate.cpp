class Solution {
public:
    pair<bool, int> bfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        bool flag = false;
        int dr[] = {1, 0};
        int dc[] = {0, 1};
        vis[i][j] = true;
        q.push({i, j});
        int cnt = 0;

        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int row = temp.first;
            int col = temp.second;
            for(int k = row+1; k < n; k++){
                if(vis[k][col]){
                    flag = true;
                    continue;
                }
                if(grid[k][col] == 1 && !vis[k][col]){
                    q.push({k, col});
                    vis[k][col] = true;
                    cnt++;
                    flag = true;
                }
            }
            for(int k = col+1; k < m; k++){
                if(vis[row][k]){
                    flag = true;
                    continue;
                }
                if(grid[row][k] == 1 && !vis[row][k]){
                    q.push({row, k});
                    vis[row][k] = true;
                    cnt++;
                    flag = true;
                }
            }
        }
        return {flag, cnt};
    }
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    auto a = bfs(grid, i, j, vis);
                    if(a.first){
                        ans += 1 + a.second;
                    }
                    
                }
            }
        }
        return ans;
    }
};