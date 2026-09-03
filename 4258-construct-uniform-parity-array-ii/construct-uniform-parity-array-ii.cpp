class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int evmin = INT_MAX, odmin = INT_MAX;
        // int evi = 0, odi = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] % 2 == 0 && nums[i] < evmin){
                evmin = min(evmin, nums[i]);
                // evi = i;
            }
            else if(nums[i] % 2 != 0 && nums[i] < odmin){
                odmin = min(odmin, nums[i]);
                // odi = i;
            }
        }
        if(evmin - odmin < 1 && evmin != INT_MAX && odmin != INT_MAX) return false;
        return true;
    }
};