class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int i = 0, j = 0;
        long long temp = 1;
        long long result = 0;
        while(j < nums.size()){
            temp *= nums[j];
            while(temp >= k){
                temp /= nums[i];
                i++;
            }
            result += j - i + 1;
            j++;
        }
        return result;
    }
};