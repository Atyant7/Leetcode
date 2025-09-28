class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mp;
        for(auto i : nums){
            mp[i]++;
        }
        int max = INT_MIN;
        for(auto &i : mp){
            if(i.second >= max) max = i.second;
        }
        int ans = 0;
        for(auto &i : mp){
            if(i.second == max) ans += max;
        }
        return ans;
    }
};