class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        for(int i = 0; i < n; i++){
            if(i != nums[i]){
                v.push_back(nums[i]);
            }
        }
        if(v.size() == 0) return 0;
        // int minele = *min_element(v.begin(), v.end());
        int minele = v[0];
        for(int i = 1; i < v.size(); i++){
            if(minele == v[i]) continue;
            minele = minele & v[i];
        }
        return minele;
    }
};