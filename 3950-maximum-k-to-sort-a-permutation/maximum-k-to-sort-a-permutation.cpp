class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        // vector<int> v;
        int minele = INT_MAX;
        for(int i = 0; i < n; i++){
            if(i != nums[i]){
                minele = minele & nums[i];
            }
        }
        // if(v.size() == 0) return 0;
        // int minele = v[0];
        // for(int i = 1; i < v.size(); i++){
        //     minele = minele & v[i];
        // }
        return minele == INT_MAX ? 0 : minele;
    }
};