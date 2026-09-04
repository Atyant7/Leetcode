class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> v(n);
        for(int i = 0 ; i < n ; i++){
            v[i] = *max_element(nums.begin() , nums.begin() + i+1) - *min_element(nums.begin()+i, nums.end());
        }
        for(int i = 0 ; i < n ; i++){
            if(v[i] <= k) return i;
        }
        return -1;
    }
};