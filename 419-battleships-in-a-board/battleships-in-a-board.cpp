class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& vis){
        int m = grid.size();
        int n = grid[0].size();
        vis[i][j] = true;
        if(i-1 >= 0 && grid[i-1][j] == 'X' && vis[i-1][j] == false) dfs(grid, i-1, j, vis);
        if(i+1 <= m - 1 && grid[i+1][j] == 'X' && vis[i+1][j] == false) dfs(grid, i+1, j, vis);
        if(j - 1 >= 0 && grid[i][j-1] == 'X' && vis[i][j-1] == false) dfs(grid, i, j-1, vis);
        if(j+1 <= n-1 && grid[i][j+1] == 'X' && vis[i][j+1] == false) dfs(grid, i, j+1, vis);
    }
    int countBattleships(vector<vector<char>>& grid) {
        int n = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(col, false));
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < col ; j++){
                if(grid[i][j] == 'X' && !vis[i][j]){
                    //bfs(grid, i, j, vis);
                    dfs(grid, i, j, vis);
                    count++;
                }
            }
        }
        return count;
    }
};