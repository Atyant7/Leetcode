class Solution {
public:
    void bfs(vector<vector<char>>& board, int i, int j,
             vector<vector<bool>>& vis) {
        int n = board.size();
        int m = board[0].size();

        vector<pair<int, int>> v;
        queue<pair<int, int>> q;

        vis[i][j] = true;
        q.push(make_pair(i, j));
        v.push_back(make_pair(i, j));

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        bool flag = false;

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
                if (board[nrow][ncol] == 'T') {
                    flag = true;
                    continue;
                }
                if (board[nrow][ncol] == 'O' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = true;
                    v.push_back(make_pair(nrow, ncol));
                    q.push(make_pair(nrow, ncol));
                }
            }
        }
        if (!flag) {
            for (int i = 0; i < v.size(); i++) {
                auto a = v[i];
                board[a.first][a.second] = 'X';
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int cnt = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O')
                board[i][0] = 'T';

            if (board[i][m - 1] == 'O')
                board[i][m - 1] = 'T';

            vis[i][0] = true;
            vis[i][m - 1] = true;
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O')
                board[0][j] = 'T';

            if (board[n - 1][j] == 'O')
                board[n - 1][j] = 'T';

            vis[0][j] = true;
            vis[n - 1][j] = true;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                // if (board[i][j] == 'O') {
                //     if (board[i - 1][j] == 'X' && board[i + 1][j] == 'X' &&
                //         board[i][j - 1] == 'X' && board[i][j + 1] == 'X') {
                //         vis[i][j] = true;
                //         board[i][j] = 'X';
                //     }
                // }
                if (board[i][j] == 'O' && !vis[i][j]) {
                    bfs(board, i, j, vis);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'T')
                board[i][0] = 'O';

            if (board[i][m - 1] == 'T')
                board[i][m - 1] = 'O';
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'T')
                board[0][j] = 'O';

            if (board[n - 1][j] == 'T')
                board[n - 1][j] = 'O';
        }
    }
};