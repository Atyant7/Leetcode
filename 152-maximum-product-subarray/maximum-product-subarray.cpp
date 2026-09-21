class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int temp = nums[0];
        for(int i = 0; i < n; i++){
            int prod = 1;
            for(int j = i; j < n; j++){
                prod *= nums[j];
                ans = max(ans, prod);
            }
        }
        return ans;
    }
};