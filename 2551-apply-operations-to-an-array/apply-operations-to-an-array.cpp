class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(nums.begin(), nums.end());
        for(int i = 0; i < n-1; i++){
            if(v[i] == v[i+1]){
                v[i] *= 2;
                v[i+1] = 0;
                i++;
            }
        }
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            if(v[i] == 0){
                continue;
            }
            else{
                v[j] = v[i];
                j++;
            }
        }
        for(int i = j; i < v.size(); i++){
            v[i] = 0;
        }
        return v;
    }
};