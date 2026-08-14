class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& vis){
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        vis[i][j] = true;
        while(q.size() > 0){
            auto a = q.front();
            q.pop();
            int row = a.first;
            int col = a.second;
            if(row - 1 >= 0 && !vis[row-1][col] && grid[row-1][col] == '1'){
                vis[row-1][col] = true;
                q.push(make_pair(row-1, col));
            }
            if(row + 1 < grid.size() && !vis[row+1][col] && grid[row+1][col] == '1'){
                vis[row+1][col] = true;
                q.push(make_pair(row+1, col));
            }
            if(col - 1 >= 0 && !vis[row][col-1] && grid[row][col-1] == '1'){
                vis[row][col-1] = true;
                q.push(make_pair(row, col-1));
            }
            if(col + 1 < grid[0].size() && !vis[row][col+1] && grid[row][col+1] == '1'){
                vis[row][col+1] = true;
                q.push(make_pair(row, col+1));
            }
        }
        
    }

    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& vis){
        int m = grid.size();
        int n = grid[0].size();
        vis[i][j] = true;
        if(i-1 >= 0 && grid[i-1][j] == '1' && vis[i-1][j] == false) dfs(grid, i-1, j, vis);
        if(i+1 <= m - 1 && grid[i+1][j] == '1' && vis[i+1][j] == false) dfs(grid, i+1, j, vis);
        if(j - 1 >= 0 && grid[i][j-1] == '1' && vis[i][j-1] == false) dfs(grid, i, j-1, vis);
        if(j+1 <= n-1 && grid[i][j+1] == '1' && vis[i][j+1] == false) dfs(grid, i, j+1, vis);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(col, false));
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < col ; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    //bfs(grid, i, j, vis);
                    dfs(grid, i, j, vis);
                    count++;
                }
            }
        }
        return count;
    }
};