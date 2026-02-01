class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int temp = 1;
        int temp2 = 1;
        int noz = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0) noz++;
            temp *= nums[i];
            if(nums[i] != 0){
                temp2 *= nums[i];
            }
        }
        if(noz > 1) temp2 = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0) nums[i] = temp2;
            else nums[i] = temp/nums[i];
        }
        return nums;
    }
};