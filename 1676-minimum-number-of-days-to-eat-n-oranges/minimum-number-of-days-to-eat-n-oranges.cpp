class Solution {
public:
    unordered_map<int, int> dp;

    int c(int n) {
        if (n <= 1) return n;

        if (dp.count(n)) return dp[n];

        int by2 = n % 2 + 1 + c(n / 2);
        int by3 = n % 3 + 1 + c(n / 3);

        return dp[n] = min(by2, by3);
    }

    int minDays(int n) {
        return c(n);
    }
};