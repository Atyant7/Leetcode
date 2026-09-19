// dp = memoisation
class Solution1{
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

// dp = tabulation
class Solution {
public:
    bool isPerfect(int n){
        int temp = int(sqrt(n));
        return temp*temp == n ? true : false;
    }
    int numSquares(int n){
        vector<int> dp(n+1, -1);
        for(int i = 1; i <= n; i++){
            if(isPerfect(i)) dp[i] = 1;
            else{
                int mine = INT_MAX;
                for(int j = 1; j * j <= i ; j++){
                    int cnt = dp[j*j] + dp[i - j * j];
                    mine = min(mine, cnt);
                }
                dp[i] = mine;
            }
        }
        return dp[n];
    }
};