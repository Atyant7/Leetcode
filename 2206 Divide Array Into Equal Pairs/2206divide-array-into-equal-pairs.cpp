class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int size = nums.size();
        if(size % 2 != 0) return false;
            unordered_map<int , int> freq;
            for(auto &val : nums){
                freq[val]++;
            }
            for(auto &[key, value]: freq){
                if(value % 2 != 0){
                    return false;
                }
            }
        
        return true;
    }
};