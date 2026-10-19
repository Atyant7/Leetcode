class Solution {
public:
    int insertpos(vector<int>& nums, int target){
        int st = 0;
        int end = nums.size() - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return st;
    }
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int idx = insertpos(nums, x);

        int left = idx - 1;
        int right = idx;

        while (k--) {
            if (left < 0) {
                right++;
            }
            else if (right >= n) {
                left--;
            }
            else if (abs(nums[left] - x) <= abs(nums[right] - x)) {
                left--;
            }
            else {
                right++;
            }
        }

        // Selected range is [left + 1, right - 1]
        vector<int> ans;
        for (int i = left + 1; i < right; i++) {
            ans.push_back(nums[i]);
        }

        return ans;

    }
};