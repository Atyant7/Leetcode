class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for(int i = 0 ; i < n ; i++){
            mp[nums[i]]++;
        }
        vector<int> ans;
        for(auto a : mp){
            if(a.second > 1){
                ans.push_back(a.first);
            }
        }
        return ans;
    }
};