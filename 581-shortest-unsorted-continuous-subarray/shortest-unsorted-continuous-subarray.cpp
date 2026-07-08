class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v(nums.size());
        for(int i = 0; i < nums.size() ; i++){
            v[i] = nums[i];
        }
        sort(v.begin(), v.end());
        int start = -1;
        int last = -1;
        for(int i = 0 ; i < nums.size() ; i++){
            if(v[i] != nums[i]){
                start = i;
                break;
            }
        }
        if(start == -1) return 0;
        for(int i = nums.size() - 1 ; i >= 0 ; i--){
            if(v[i] != nums[i]){
                last = i;
                break;
            }
        }
        return last - start + 1;
    }
};