class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pmax(n), pmin(n);
        pmax[0] = nums[0];
        for(int i = 1 ; i < n ; i++){
            pmax[i] = max(nums[i] , pmax[i-1]);
        }
        pmin[n-1] = nums[n-1];
        for(int i = n - 2 ; i >= 0; i--){
            pmin[i] = min(nums[i] , pmin[i+1]);
        }
        for(int i = 0 ; i < n ; i++){
            pmax[i] = pmax[i] - pmin[i];
        }
        for(int i = 0 ; i < n ; i++){
            if(pmax[i] <= k) return i;
        }
        return -1;
    }
};