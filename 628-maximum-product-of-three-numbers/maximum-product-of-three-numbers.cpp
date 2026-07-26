class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size() - 1;
        int maxi = 0;
        if(nums[0] < 0 && nums[1] < 0){
            maxi = nums[0] * nums[1];
        }
        return max(maxi * nums[n], nums[n]*nums[n-1]*nums[n-2]);
    }
};