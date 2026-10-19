class Solution {
public:
    int dfs(vector<int>& nums, int i, int end, vector<int>& dp) {
        if (i > end) return 0;

        if (dp[i] != -1) return dp[i];

        int skip = dfs(nums, i + 1, end, dp);
        int take = nums[i] + dfs(nums, i + 2, end, dp);

        return dp[i] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        // Case 1: First house allowed, last excluded
        int first = dfs(nums, 0, n - 2, dp1);

        // Case 2: First house excluded, last allowed
        int second = dfs(nums, 1, n - 1, dp2);

        return max(first, second);
    }
};