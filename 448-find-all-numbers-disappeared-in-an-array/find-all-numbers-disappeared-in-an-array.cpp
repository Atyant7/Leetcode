class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_set<int> s;
        for(int i = 1; i <= n; i++){
            s.insert(i);
        }
        for(int i = 0; i < n; i++){
            s.erase(nums[i]);
        }
        for(int a : s){
            ans.push_back(a);
        }
        return ans;
    }
};