class Solution {
public:
    int f1(const string &s, int i, vector<int> &dp){
        if(dp[i] != -1) return dp[i];
        if(i == s.size()) return dp[i] = 1;
        if(s[i] == '0') return 0;
        int cnt = f1(s, i+1, dp);
        if((i+1 < s.size()) && (10 * (s[i] - '0') + (s[i+1] - '0')) <= 26) cnt += f1(s, i+2, dp) ;
        return dp[i] = cnt;

    }
    int numDecodings(string s) {
        vector<int> dp(s.size() +1, -1);
        int ans = f1(s, 0, dp);
        return ans;
    }
};