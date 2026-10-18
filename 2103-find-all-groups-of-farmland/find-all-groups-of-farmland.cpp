// bfs
// Time Complexity: O(n x m)
// Space Complexity: O(n x m)
class Solution1 {
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


//Approach-3 (Brute Force Greedy)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        
        vector<vector<int>> result;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(land[i][j] == 0) continue;
                
                //find the right most column of the current group
                int c1 = j;
                while(c1 < n && land[i][c1] == 1) {
                    c1++;
                }
                
                //find the bottom most row of the current group
                int r1 = i;
                while(r1 < m && land[r1][j] == 1) {
                    r1++;
                }
                
                c1 = c1 == 0 ?  c1 : c1-1;
                r1 = r1 == 0 ?  r1 : r1-1;
                
                result.push_back({i, j, r1, c1});
                
                
                //mark all the inbetween 1s to 0s
                for(int k = i; k <= r1; k++) {
                    for(int l = j; l <= c1; l++) {
                        land[k][l] = 0; //visited
                    }
                }
                
                
            }
        }
        
        return result;
        
        
    }
};