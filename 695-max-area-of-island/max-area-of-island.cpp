class Solution {
public:
    int bfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        int cnt = 1;
        vis[i][j] = true;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            // cnt++;
            int row = temp.first;
            int col = temp.second;
            for(int i = 0; i < 4; i++){
                int newr = row + dr[i];
                int newc = col + dc[i];
                if((newr >= 0 && newr < n) && (newc >= 0 && newc < m) && grid[newr][newc] == 1 && (vis[newr][newc] == false)){
                    cnt++;
                    vis[newr][newc] = true;
                    q.push(make_pair(newr, newc));
                }
            }
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = INT_MIN;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] == false){
                    int temp = bfs(grid, i, j, vis);
                    ans = max(ans, temp);
                }
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }
};