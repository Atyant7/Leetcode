
class Solution {
public:
    int dfs(vector<int>& nums, int i, int sum,
            int target, vector<vector<int>>& dp) {

        if(sum == target) {
            return 0;
        }

        if(i == nums.size() || sum > target) {
            return -1e9;
        }

        if(dp[i][sum] != -1) {
            return dp[i][sum];
        }

        // Take
        int take = 1 + dfs(nums, i + 1, sum + nums[i],
                           target, dp);

        // Skip
        int skip = dfs(nums, i + 1, sum,
                       target, dp);

        return dp[i][sum] = max(take, skip);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        int ans = dfs(nums, 0, 0, target, dp);

        return ans < 0 ? -1 : ans;
    }
};
