class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for (int i = 0; i <= min(limit, n); i++) {
            int low = max(0, n - i - limit);
            int high = min(limit, n - i);
            if (low <= high)
                ans += (high - low + 1);
        }
        return ans;
    }
};