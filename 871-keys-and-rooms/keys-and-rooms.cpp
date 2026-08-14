class Solution {
public:

    void dfs(int i, vector<vector<int>> adj, vector<bool>& vis){
        vis[i] = true;
        for(int j = 0 ; j < adj[i].size() ; j++){
            if(vis[adj[i][j]] == false) dfs(adj[i][j], adj, vis);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        // queue<int> q;
        visited[0] = true;
        // q.push(0);
        // while(q.size() > 0){
        //     int front = q.front();
        //     q.pop();
        //     for(int i = 0 ; i < rooms[front].size() ; i++){
        //         if(!visited[rooms[front][i]]){
        //             visited[rooms[front][i]] = true;
        //             q.push(rooms[front][i]);
        //         }
        //     }
        // }
        dfs(0, rooms, visited);
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]) return false;
        }
        return true;
    }
};