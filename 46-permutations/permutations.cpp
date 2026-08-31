class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> perm;
        vector<bool> available(n, true);
        vector<vector<int>> all;
        dfs(nums, perm, available, all);
        return all;
    }

    void dfs(vector<int>& nums, vector<int>& perm, vector<bool>& available, vector<vector<int>>& all){
        if(perm.size() == nums.size()){
            all.push_back(perm);
        }
        else{
            for(int i = 0 ; i < nums.size() ; i++){
                if(available[i]){
                    perm.push_back(nums[i]);
                    available[i] = false;

                    dfs(nums, perm, available, all);

                    available[i] = true;
                    perm.pop_back();
                }
            }
        }
    }
};