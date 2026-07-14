class Solution {
public:
// Memoization
// int minCost(vector<int> cost , int idx, vector<int>& dp){
//     if(idx == 0 || idx == 1) return cost[idx];
//     if(dp[idx] != -1) return dp[idx];
//     return dp[idx] = cost[idx] + min(minCost(cost , idx-1 , dp) , minCost(cost , idx - 2 , dp));
// }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        dp[0] = cost[0] ; 
        dp[1] = cost[1];
        for(int i = 2 ; i < n ; i++){
            dp[i] = cost[i] + min(dp[i-1] , dp[i-2]);
        }
        return min(dp[n-1] , dp[n-2]);
    }
};