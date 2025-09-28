class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        int per = 0;
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i < n - 2 ; i++){
            if(((nums[i] + nums[i+1]) > nums[i+2]) && ((nums[i] <= nums[i+2]) && (nums[i+1] <= nums[i+2]))){
                per = max(per , nums[i]+nums[i+1]+nums[i+2]) ;
            }
        }
        return per;
    }
};