class Solution {
public:
    int dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[node] = true;
        int cnt = 1;

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                cnt += dfs(nei, adj, vis);
            }
        }

        return cnt;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);

        for (auto a : edges) {
            int u = a[0];
            int v = a[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n, false);
        long long ans = 0;
        long long processed = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                long long size = dfs(i, adj, vis);

                ans += size * processed;
                processed += size;
            }
        }
        return ans;
        
    }
};