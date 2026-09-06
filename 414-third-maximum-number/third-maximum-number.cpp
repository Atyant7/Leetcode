class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0] , nums[1]);
        set<int> s;
        for(int i = 0 ; i < nums.size() ; i++){
            s.insert(nums[i]);
        }
        vector<int> v;
        for(auto a : s){
            v.push_back(a);
        }
        sort(v.begin() , v.end() , greater<int>());
        if(v.size() < 3) return *max_element(v.begin(), v.end());
        return v[2];
    }
};