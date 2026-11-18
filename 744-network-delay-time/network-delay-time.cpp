class Solution {
public:
    void dfs(vector<vector<pair<int, int>>>& adj, vector<int>& dis, int start, int w){
        if(adj[start].size() == 0) return;
        for(auto a : adj[start]){
            if((w + a.second) < dis[a.first]){
                dis[a.first] = w + a.second;
                dfs(adj, dis, a.first, w + a.second);
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(int i = 0; i < times.size(); i++){
            pair<int, int> temp = {times[i][1], times[i][2]};
            adj[times[i][0]].push_back(temp);
        }
        vector<int> dis(n+1, INT_MAX);
        dis[k] = 0;
        dfs(adj, dis, k, 0);
        int res = INT_MIN;
        for(int i = 1; i <= n; i++){
            if(dis[i] == INT_MAX) return -1;
            res = max(res, dis[i]);
        }
        return res;
    }
};