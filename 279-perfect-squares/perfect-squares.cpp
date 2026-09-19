class Solution {
public:
    bool isPerfect(int n){
        int temp = int(sqrt(n));
        return temp*temp == n ? true : false;
    }
    int minSquares(int n, vector<int> &dp) {
        if(isPerfect(n)) return 1;
        if(dp[n] != -1) return dp[n];
        int minans = n;
        for(int i = 1; i*i <= n; i++){
            int cnt = minSquares(i*i, dp) + minSquares(n-i*i, dp);
            minans = min(cnt, minans);
        }
        dp[n] = minans;
        return minans;

    }
    int numSquares(int n) {
        if(isPerfect(n)) return 1;
        vector<int> dp(n+1, -1);
        return minSquares(n, dp);

    }
};