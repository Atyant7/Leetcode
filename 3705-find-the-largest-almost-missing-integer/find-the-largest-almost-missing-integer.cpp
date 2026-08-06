class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i = 0 ; i <= n - k ; i++){
            unordered_set<int> st;
            for(int j = i ; j < i + k ; j++){
                if(st.find(nums[j]) == st.end()){
                    mp[nums[j]]++;
                }
                st.insert(nums[j]);
            }
        }
        int ans = INT_MIN;
        for(auto a : mp){
            if(a.second == 1){
                ans = max(ans, a.first);
            }
        }
        if(ans == INT_MIN) return -1;
        return ans;
    }
};