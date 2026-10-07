class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        int si = entrance[0];
        int sj = entrance[1];
        queue<vector<int>> q;
        q.push({si, sj, 0});
        while(!q.empty()){
            int level = q.size();
            for(int i = 0; i < level; i++){
                vector<int> temp = q.front();
                q.pop();
                if((temp[0] == 0 || temp[0] == n-1 || temp[1] == 0 || temp[1] == m-1) && !(temp[0] == si && temp[1] == sj)){
                    return temp[2];
                }
                if(temp[0] - 1 >= 0 && maze[temp[0] - 1][temp[1]] != '+'){
                    q.push({temp[0] - 1, temp[1], temp[2]+1});
                    maze[temp[0] - 1][temp[1]] = '+';
                }
                if(temp[0] + 1 < n && maze[temp[0] + 1][temp[1]] != '+'){
                    q.push({temp[0] + 1, temp[1], temp[2]+1});
                    maze[temp[0] + 1][temp[1]] = '+';
                }
                if(temp[1] - 1 >= 0 && maze[temp[0]][temp[1] -1] != '+'){
                    q.push({temp[0], temp[1] - 1, temp[2]+1});
                    maze[temp[0]][temp[1] - 1] = '+';
                }
                if(temp[1] + 1 < m && maze[temp[0]][temp[1] + 1] != '+'){
                    q.push({temp[0], temp[1] + 1, temp[2]+1});
                    maze[temp[0]][temp[1] + 1] = '+';
                }
            }
        }
        return -1;
    }
};