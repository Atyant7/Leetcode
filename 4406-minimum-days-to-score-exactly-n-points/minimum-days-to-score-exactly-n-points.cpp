class Solution {
public:
    int check(int n, vector<int>& vis){
        if(n == 0) return 0;
        if(vis[n] != -1) return vis[n];
        int ans = INT_MAX;
        for(int k = 1; k*(k+1)/2 <= n; k++){
            int point = k*(k+1)/2;
            ans = min(ans, k+1+check(n-point, vis));
        }
        return vis[n] = ans;
    }
    int minDays(int n) {
        vector<int> vis(n+1, -1);
        return check(n, vis)-1;
    }
};