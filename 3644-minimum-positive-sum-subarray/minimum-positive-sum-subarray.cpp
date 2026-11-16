class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            int temp = 0;
            for(int j = i; j < nums.size(); j++){
                temp += nums[j];
                if(j-i+1 >= l && j-i+1 <= r && temp > 0){
                    ans = min(ans, temp);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};