class Solution {
public:
    int helper(vector<int>& n, int start, int end){
        if( start >= end ) return n[start];
        if(n[start] <= n[end]){
            return n[start];
        }
        int mid = start + (end - start) / 2;
        int left = helper(n, start, mid);
        int right = helper(n, mid+1, end);
        return min(left, right);
    }
    int findMin(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return min(nums[0] , nums[1]);
        if(nums[0] < nums[nums.size() - 1]) return nums[0];
        return helper(nums, 0, nums.size() - 1);
    }
};