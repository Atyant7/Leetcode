class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        mp[0] = 1;
        int temp = 0 ;
        int cnt = 0;
        for(int num : nums){
            temp += num;
            if(mp.find(temp - k) != mp.end()){
                cnt += mp[temp - k];
            }
            mp[temp]++;
        }
        return cnt;
    }
};