class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        unordered_set<int> s;
        for(int i = 0; i < n; i++){
            s.insert(nums[i]);
            if(s.size() == 3){
                return nums[i];
            }
        }
        return nums[0];
    }
};