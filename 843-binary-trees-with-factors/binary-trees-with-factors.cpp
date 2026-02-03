class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        sort(arr.begin(), arr.end());

        unordered_map<int, long long> dp;

        for (int x : arr)
            dp[x] = 1; // base case

        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) {
                    int right = arr[i] / arr[j];
                    if (dp.find(right) != dp.end()) {
                        dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[right]) % MOD;
                    }
                }
            }
        }

        long long ans = 0;
        for (auto& p : dp)
            ans = (ans + p.second) % MOD;
        return ans;
    }
};