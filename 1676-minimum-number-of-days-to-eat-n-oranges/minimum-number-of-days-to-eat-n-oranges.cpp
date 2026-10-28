class Solution {
public:
    unordered_map<int, int> dp;

    int f(int n) {
        if (n <= 1) return n;

        if (dp.count(n)) return dp[n];

        // int by2 = n % 2 + 1 + c(n / 2);
        // int by3 = n % 3 + 1 + c(n / 3);

        return dp[n] = 1 + min((n%2) + f(n/2), (n%3) + f(n/3)) ;
    }

    int minDays(int n) {
        return f(n);
    }
};