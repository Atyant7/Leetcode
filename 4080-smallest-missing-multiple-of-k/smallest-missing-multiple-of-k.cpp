class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        int maxele = *max_element(nums.begin() , nums.end());
        set<int> temp;
        int i = k;
        for(i ; i <= maxele ; i = i + k){
            temp.insert(i);
        }
        for(int i = 0 ; i < n ; i++){
            if(nums[i] % k == 0){
                temp.erase(nums[i]);
            }
        }
        if(temp.empty()) return i;
        return *temp.begin();
    }
};