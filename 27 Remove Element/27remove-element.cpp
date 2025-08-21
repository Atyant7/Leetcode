class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> result;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(nums[i] != val){
                result.push_back(nums[i]);
            }
        }
        for(int i = 0 ; i < n ; i++){
            nums.pop_back();
        }
        for(int i = 0 ; i < result.size() ; i++){
            nums.push_back(result[i]);
        }
        return nums.size();
    }
};