class Solution {
public:
    bool ans;
    void bfs(int i, vector<vector<int>> &adj, vector<int> &vis){
        queue<int> q;
        q.push(i);
        while(q.size() > 0){
            int front = q.front();
            q.pop();
            int color = vis[front];
            for(int ele : adj[front]){
                if(vis[ele] == -1){
                    vis[ele] = 1 - color;
                    q.push(ele);
                }
                if(vis[ele] == vis[front]){
                    ans = false;
                    return;
                }
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        ans = true;
        int n = graph.size();
        vector<int> vis(n, -1);
        vis[0] = 0; // 0 -> blue, 1 -> red.
        for(int i = 0 ; i < n ; i++){
            if(i == 0 || vis[i] == -1) bfs(i, graph, vis);
        }
        return ans;
    }
};