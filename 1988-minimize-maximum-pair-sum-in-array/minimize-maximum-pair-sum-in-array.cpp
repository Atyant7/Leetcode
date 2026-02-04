class Solution {
public:
    int minPairSum(vector<int>& nums) {
        vector<int> freq(100001, 0);
        for (int x : nums)
            freq[x]++;

        int low = 1, high = 100000;
        int ans = 0;

        while (low <= high) {
            while (low <= high && freq[low] == 0)
                low++;
            while (low <= high && freq[high] == 0)
                high--;

            if (low > high)
                break;

            ans = max(ans, low + high);
            freq[low]--;
            freq[high]--;
        }
        return ans;
    }
};