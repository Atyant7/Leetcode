class Solution {
public:
    int bs(vector<int>& nums, int st, int end){
        if(st > end) return -1;
        int mid = st + (end - st)/2;
        if((mid-1 >= 0 && mid+1 < nums.size()) && (nums[mid-1] != nums[mid] && nums[mid+1] != nums[mid])){
            return nums[mid];
        }
        int left = bs(nums, st, mid-1);
        int right = bs(nums, mid+1, end);
        if(left == -1) return right;
        return left;
    }
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[nums.size() - 2] != nums[nums.size()-1]) return nums[nums.size()-1];
        return bs(nums, 0, nums.size()-1);
    }
};
