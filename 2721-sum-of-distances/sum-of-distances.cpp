class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();

        map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(n, 0);

        for (auto a : mp) {
            vector<int> temp = a.second;
            int m = temp.size();

            // Prefix sum of positions
            vector<long long> prefix(m + 1, 0);

            for (int i = 0; i < m; i++) {
                prefix[i + 1] = prefix[i] + temp[i];
            }

            for (int i = 0; i < m; i++) {
                // Distance from temp[i] to all positions on the left
                long long left = 1LL * temp[i] * i - prefix[i];

                // Distance from temp[i] to all positions on the right
                long long right =
                    (prefix[m] - prefix[i + 1]) - 1LL * temp[i] * (m - i - 1);

                ans[temp[i]] = left + right;
            }
        }

        return ans;
    }
};