class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        if(nums[0] == 0) return 0;
        vector<int> vneg;
        vector<int> vpos;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] < 0) vneg.push_back(nums[i]);
            else vpos.push_back(nums[i]);
        }
        if(int(vneg.size()) != 0 && int(vpos.size() != 0)){
            sort(vneg.begin() , vneg.end());
            sort(vpos.begin() , vpos.end());
            if(abs(vneg[int(vneg.size()) - 1]) >= vpos[0]){
                return vpos[0];
            }
            else return vneg[int(vneg.size()) - 1];
        }
        else if(int(vneg.size())!= 0 && int(vpos.size()) == 0){
            sort(vneg.begin() , vneg.end());
            return vneg[int(vneg.size()) - 1];
        }
        sort(vpos.begin() , vpos.end());
        return vpos[0];

    }
};