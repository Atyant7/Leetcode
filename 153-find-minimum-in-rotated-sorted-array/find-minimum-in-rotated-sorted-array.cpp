class Solution {
public:
    int binarySearch(vector<int>& arr, int start, int end) {
        if (start > end)
            return INT_MAX;
        if (start == end)
            return arr[start];
        int mid = start + (end - start) / 2;
        if (mid > 0 && mid < arr.size() - 1) {
            if ((arr[mid] < arr[mid - 1]) && (arr[mid] < arr[mid + 1]))
                return arr[mid];
            else if ((arr[mid] > arr[mid - 1]) && (arr[mid] > arr[mid + 1])) {
                return arr[mid + 1];
            }
        }
        int left = binarySearch(arr, start, mid - 1);
        int right = binarySearch(arr, mid + 1, end);
        return min(left, right);
    }
    int findMin(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        if (nums[0] < nums.back())
            return nums[0];
        return binarySearch(nums, 0, nums.size() - 1);
    }
};