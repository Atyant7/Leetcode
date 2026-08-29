class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int idx=-1;
        // step1- finding pivot index
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;
                break;
            }
        }
        if(idx==-1){ //if array is already largest
            reverse(nums.begin(),nums.end());
            return;
        }
        //step2- sorting after pivot
        reverse(nums.begin()+idx+1,nums.end());
        // step3- idx+1 to end tak mein find kro just greater number ka index aur fir swap krdo idx aur just greater wale      ko
        int j=-1;
        for(int i=idx+1;i<n;i++){
            if(nums[i]>nums[idx]){
                j=i;
                break;
            }
        }
        // step4- swapping idx and j wale elements
        int temp=nums[idx];
        nums[idx]=nums[j];
        nums[j]=temp;
        return;
    }
};