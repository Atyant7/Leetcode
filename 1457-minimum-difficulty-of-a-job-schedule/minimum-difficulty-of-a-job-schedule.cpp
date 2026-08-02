class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(vector<int>& job, int idx, int days) {
        if (days == 1) {
            return *max_element(job.begin() + idx, job.end());
        }
        if (dp[idx][days] != -1)
            return dp[idx][days];

        int ans = INT_MAX;
        int mx = 0;
        for (int j = idx; j <= n - days; j++) {
            mx = max(mx, job[j]);
            ans = min(ans, mx + solve(job, j + 1, days - 1));
        }
        return dp[idx][days] = ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n = jobDifficulty.size();
        if (n < d)
            return -1;
        dp.assign(n, vector<int>(d + 1, -1));
        return solve(jobDifficulty, 0, d);
    }
};