class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        // Prefix sum
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        // Suffix sum
        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + nums[i];
        }
        int ans = INT_MAX;
        // -----------------------------
        // Suffix only
        // -----------------------------
        for (int j = n - 1; j >= 0; j--) {
            if (suffix[j] == x) {
                ans = min(ans, n - j);
            }
        }
        // -----------------------------
        // Prefix only
        // -----------------------------
        for (int i = 0; i < n; i++) {
            if (prefix[i] == x) {
                ans = min(ans, i + 1);
            }
        }
        // -----------------------------
        // Store suffix sums
        // -----------------------------
        unordered_map<int, int> mp;
        for (int j = 0; j < n; j++) {
            // Store the rightmost starting index
            mp[suffix[j]] = j;
        }
        // -----------------------------
        // Prefix + Suffix
        // -----------------------------
        for (int i = 0; i < n; i++) {
            int remaining = x - prefix[i];
            if (mp.find(remaining) != mp.end()) {
                int j = mp[remaining];
                // Prefix ends at i
                // Suffix starts at j
                // They must not overlap
                if (j > i) {
                    int operations = (i + 1) + (n - j);
                    ans = min(ans, operations);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};