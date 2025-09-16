class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int , int> mp;
        for(auto i : nums){
            mp[i]++;
        }
        int ok;
        for(auto &i : mp){
            if(i.second == 1){
                ok = i.first;
            }
        }
        return ok;
    }
};