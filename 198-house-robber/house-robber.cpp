// memoization
class Solution1 {
public:
    int dfs(vector<int> & nums, int i, vector<int>& dp){
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int skip = dfs(nums, i+1, dp);
        int take = nums[i] + dfs(nums, i+2, dp);
        return dp[i] = max(take, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return dfs(nums, 0, dp);
    }
};

class Solution {
public:
    int rob(vector<int>& nums){
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0] , nums[1]);
        for(int i = 2 ; i < n ; i++){
            dp[i] = max(nums[i] + dp[i - 2] , dp[i-1]);
        }
        return dp[n-1];
    }
};