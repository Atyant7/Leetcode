class Solution {
public:
    void bfs(int i, vector<bool>& vis, vector<vector<int>>& adj){
        int n = adj.size();
        vis[i] = true;
        queue<int> q;
        q.push(i);
        while(q.size() > 0){
            int f = q.front();
            q.pop();
            for(int j = 0 ; j < n ; j++){
                if(adj[f][j] == 1 && vis[j] == false){
                    q.push(j);
                    vis[j] = true;
                }
            }
        }
    }
    void dfs(int i, vector<bool>& vis, vector<vector<int>>& adj){
        int n = adj.size();
        vis[i] = true;
        for(int j = 0 ; j < n ; j++){
            if(adj[i][j] == 1 && vis[j] == false){
                dfs(j, vis, adj);
            } 
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<bool> visited(n, false);
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                //bfs(i, visited, isConnected);
                dfs(i, visited, isConnected);
                count++;
            }
        }
        return count;
    }
};