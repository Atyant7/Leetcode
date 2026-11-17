class Solution {
public:
    int dfs(vector<int>& nums, int i, int jump, vector<int>& dp){
        if(i == nums.size() || i > nums.size()) return nums.size()+1;
        if(i == nums.size() - 1) return 0;
        if(dp[i] != -1) return dp[i];
        int skip = 1 + dfs(nums, i+1, jump, dp);
        int take = 0;
        for(int j = 1; j <= nums[i]; j++){
            take = 1 + dfs(nums, i+j, jump, dp);
            jump = min({jump, take, skip});
        }
        return dp[i] = jump;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return dfs(nums, 0, nums.size()+1, dp);
    }
};