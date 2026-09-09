class Solution {
    int n;

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();

        vector<vector<int>> all;
        vector<int> par;

        par.push_back(0);

        dfs(graph, 0, par, all);

        return all;
    }

private:
    void dfs(vector<vector<int>>& graph, int s,
             vector<int>& par, vector<vector<int>>& all) {

        if (s == n - 1)
            all.push_back(par);
        else {
            for (int v : graph[s]) {
                par.push_back(v);

                dfs(graph, v, par, all);

                par.pop_back();
            }
        }
    }
};