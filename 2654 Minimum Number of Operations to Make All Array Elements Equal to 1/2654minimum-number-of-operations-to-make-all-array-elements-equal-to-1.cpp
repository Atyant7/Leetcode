class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ones = count(nums.begin(), nums.end(), 1);

        // Case 1: Already have 1s
        if (ones > 0)
            return n - ones;

        // Case 2: Find smallest subarray with gcd == 1
        int minLen = INT_MAX;
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    minLen = min(minLen, j - i + 1);
                    break;  // no need to extend this subarray
                }
            }
        }

        if (minLen == INT_MAX)
            return -1;  // no subarray with gcd 1

        // (minLen - 1) to create one 1, then (n - 1) to spread it
        return (minLen - 1) + (n - 1);

    }
};