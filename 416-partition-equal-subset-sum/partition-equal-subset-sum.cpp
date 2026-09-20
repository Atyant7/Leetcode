class Solution {
public:
    bool subset(int i, vector<int> &v, int target, vector<vector<int>> &dp){
        if(i == v.size()){
            if(target == 0) return true;
            return false;
        }
        if(dp[i][target] != -1) return dp[i][target];
        bool ans = false;
        bool skip = subset(i+1, v, target, dp);
        if(target - v[i] < 0) ans = skip;
        else{
            bool pick = subset(i+1, v, target - v[i], dp);
            ans = skip || pick;
        }
        dp[i][target] = ans ? 1 : 0;
        return ans;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size() ; i++){
            sum+=nums[i];
        }
        if(sum % 2 != 0) return false;
        int target = sum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        return subset(0, nums, target, dp);
    }
};