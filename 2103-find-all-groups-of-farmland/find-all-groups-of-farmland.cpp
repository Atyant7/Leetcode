class Solution {
public:
    pair<int, int> bfs(vector<vector<int>>& land, int i, int j, vector<vector<bool>>& vis){
        int n = land.size();
        int m = land[0].size();

        queue<pair<int, int>> q;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        q.push({i, j});
        vis[i][j] = true;
        pair<int, int> ans = {i, j};

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

                if (land[nrow][ncol] == 1 && !vis[nrow][ncol]){
                    vis[nrow][ncol] = true;
                    q.push({nrow, ncol});
                    ans = {nrow, ncol};
                }
                
            }
        }
        return ans;
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int col = land[0].size();
        vector<vector<bool>> vis(n, vector<bool>(col, false));
        vector<vector<int>> ans;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < col ; j++){
                if(land[i][j] == 1 && !vis[i][j]){
                    auto a = bfs(land, i, j, vis);
                    ans.push_back({i, j, a.first, a.second});
                }
            }
        }
        return ans;
    }
};