class Solution {
public:
    long long f1(vector<vector<int>>& nums, int i, vector<long long>& dp){
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        long long skip = f1(nums, i+1, dp);
        long long take = nums[i][0] + f1(nums, i+nums[i][1]+1, dp);
        return dp[i] = max(skip, take);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), -1);
        return f1(questions, 0, dp);
    }
};