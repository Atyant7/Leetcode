class Solution {
public:

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        queue<int> q;
        visited[0] = true;
        q.push(0);
        while(q.size() > 0){
            int front = q.front();
            q.pop();
            for(int i = 0 ; i < rooms[front].size() ; i++){
                if(!visited[rooms[front][i]]){
                    visited[rooms[front][i]] = true;
                    q.push(rooms[front][i]);
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]) return false;
        }
        return true;
    }
};