class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);   // Undirected graph
        }
        queue<int> q;
        q.push(source);
        vis[source] = true;
        q.push(source);
        vis[source] = true;

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            if (front == destination)
                return true;

            for (int neighbour : adj[front]) {
                if (!vis[neighbour]) {
                    vis[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        return false;
    }
};