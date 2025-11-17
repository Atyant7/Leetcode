class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int , vector<int>> mp;
        for(int i = 0 ; i < nums.size() ; i++){
           mp[nums[i]].push_back(i);
        }
        for(auto &p : mp){
            for(int i = 0 ; i < p.second.size() - 1; i++){
                if(abs(p.second[i] - p.second[i+1]) <= k) return true;
            }
        }
        return false;
    }
};