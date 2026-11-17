class Solution {
public:
    bool dfs(vector<int>& nums, int i, vector<int>& dp) {

        if(i >= nums.size()) return false;

        if(i == nums.size() - 1) return true;

        if(nums[i] == 0) return false;

        if(dp[i] != -1) return dp[i];

        for(int j = 1; j <= nums[i]; j++) {

            if(dfs(nums, i + j, dp)) {
                return dp[i] = 1;
            }
        }

        return dp[i] = 0;
    }

    bool canJump(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n, -1);

        return dfs(nums, 0, dp);
    }
};