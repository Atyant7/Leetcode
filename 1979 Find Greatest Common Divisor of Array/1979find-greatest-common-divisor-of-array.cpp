class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int min_num = nums[0];
        int max_num = nums[nums.size() - 1];
        while(min_num != 0){
            int temp = max_num % min_num;
            max_num = min_num;
            min_num = temp;
        }
        return max_num;
    }
};