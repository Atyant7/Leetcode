// class Solution {
// public:
//     int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
//         int cnt = 0;
//         queue<pair<int, pair<int, int>>> q;
//         q.push({0, {startRow, startColumn}});
//         v[startRow][startColumn] = 0;

//         int dr[] = {-1, 1, 0, 0};
//         int dc[] = {0, 0, -1, 1};

//         while(!q.empty()){
//             int s = q.size();

//             for(int i = 0; i < s; i++){
//                 auto a = q.front();
//                 q.pop();
//                 int dis = a.first;
//                 int r = a.second.first;
//                 int c = a.second.second;
//                 dis++;
//                 for(int i = 0; i < 4; i++){
//                     int nr = r + dr[i];
//                     int nc = c + dc[i];
//                     if(nr < 0 || nr >= m || nc < 0 || nc >= n){
//                         if(dis <= maxMove){
//                             cnt++;
//                         }
//                         continue;
//                     }
//                     if(dis > maxMove) continue;
//                     q.push({dis, {nr, nc}});
//                 }
//             }
//         }
//         return cnt;
        
//     }
// };


class Solution {
public:
    int MOD = 1e9 + 7;
    int solve(int m, int n, int moves, int r, int c, vector<vector<vector<int>>>& dp){
        if(r < 0 || r >= m || c < 0 || c >= n){
            return 1;
        }

        if(moves == 0) return 0;

        if(dp[r][c][moves] != -1){
            return dp[r][c][moves];
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        long long ans = 0;

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            ans = (ans + solve(m, n, moves-1, nr, nc, dp)) % MOD;
        }

        return dp[r][c][moves] = ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        
        return solve(m, n, maxMove, startRow, startColumn, dp);
    }
};