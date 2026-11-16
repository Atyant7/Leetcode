class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = INT_MIN;
        int dec = INT_MIN;
        int n = nums.size();
        int i = 0;
        int j = 1;
        while(i < n && j < n){
            if(nums[j] > nums[j-1]){
                inc = max(inc, j-i+1);
                j++;
            }else{
                i++;
                j = i + 1;
            }
        }
        i = 0;
        j = 1;
        while(i < n && j < n){
            if(nums[j] < nums[j-1]){
                dec = max(dec, j-i+1);
                j++;
            }else{
                i++;
                j = i + 1;
            }
        }
        return max(inc, dec) == INT_MIN ? 1 : max(inc, dec);
    }
};