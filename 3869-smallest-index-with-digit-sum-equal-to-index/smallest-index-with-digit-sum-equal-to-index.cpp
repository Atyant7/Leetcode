class Solution {
public:
    int digitSum(int n){
        int sum = 0;
        while(n != 0){
            sum = sum + n%10;
            n = n / 10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(i == digitSum(nums[i])) ans = min(ans, i);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};