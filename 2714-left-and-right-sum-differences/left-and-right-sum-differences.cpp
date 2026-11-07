class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n);
        vector<int> suf(n);
        vector<int> ans(n);
        pref[0] = 0;
        suf[n-1] = 0;
        for(int i = 1; i < n; i++){
            pref[i] = nums[i-1] + pref[i-1];
        }
        for(int i = n-2; i >= 0; i--){
            suf[i] = nums[i+1] + suf[i+1];
        }
        for(int i = 0; i < n; i++){
            ans[i] = abs(pref[i] - suf[i]);
        }
        return ans;
    }
};