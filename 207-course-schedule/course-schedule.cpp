class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj,
             vector<bool>& vis, vector<bool>& pathVis) {

        vis[node] = true;
        pathVis[node] = true;

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                if (dfs(nei, adj, vis, pathVis))
                    return true;
            }
            else if (pathVis[nei]) {
                return true;
            }
        }

        pathVis[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> pathVis(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis)) {
                    return false;
                }
            }
        }

        return true;
    }
};