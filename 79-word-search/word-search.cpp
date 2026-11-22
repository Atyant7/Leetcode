class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, int k,
             string s, vector<vector<bool>>& vis) {

        int n = board.size();
        int m = board[0].size();

        if(k == s.size()) return true;

        if(i < 0 || i >= n || j < 0 || j >= m)
            return false;

        if(vis[i][j] || board[i][j] != s[k])
            return false;

        vis[i][j] = true;

        bool right, left, up, down;
        right = left = up = down = false;

        right = dfs(board, i, j+1, k+1, s, vis);
        left  = dfs(board, i, j-1, k+1, s, vis);
        up    = dfs(board, i-1, j, k+1, s, vis);
        down  = dfs(board, i+1, j, k+1, s, vis);

        vis[i][j] = false;

        return right || left || up || down;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        bool ans = false;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0]){
                    ans = ans || dfs(board, i, j, 0, word, vis);
                }
                if(ans) return true;
            }
        }

        return ans;
    }
};