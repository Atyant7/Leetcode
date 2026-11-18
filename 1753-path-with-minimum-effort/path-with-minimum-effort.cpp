class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq;

        dis[0][0] = 0;
        pq.push({0, 0, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!pq.empty()){
            auto [effort, row, col] = pq.top();
            pq.pop();

            if(row == n-1 && col == m-1) return effort;

            if(effort > dis[row][col]) continue;

            for(int i = 0; i < 4; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

                int weight = abs(heights[row][col] - heights[nr][nc]);
                int newEffort = max(effort, weight);

                if(newEffort < dis[nr][nc]){
                    dis[nr][nc] = newEffort;
                    pq.push({newEffort, nr, nc});
                }
            }
        }
        return 0;

    }
};