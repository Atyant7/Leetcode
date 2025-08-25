class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int , int> mp;
        int n = nums.size();
        for(auto num : nums){
            mp[num]++;
        }
        int ans;
        for(auto element : mp){
            if (element.second > n/2){
                ans = element.first;
            }
        }
        return ans;
    }
};