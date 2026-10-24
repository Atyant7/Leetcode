class Solution {
public:
    int cnt = 0;
    void fun(vector<int>& a, int i, int sum, int target){
        if(i == a.size()){
            if(sum == target){
                cnt++;
            }
            return;
        }
        fun(a, i+1, sum + a[i], target);
        fun(a, i+1, sum - a[i], target);

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        // vector<
        fun(nums, 0, 0, target);
        return cnt;

    }
};