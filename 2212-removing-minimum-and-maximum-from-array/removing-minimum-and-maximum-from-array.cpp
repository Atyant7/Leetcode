class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int n = nums.size();
        int minele = *min_element(nums.begin(), nums.end());
        int maxele = *max_element(nums.begin(), nums.end());
        int mini, maxi;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == minele){
                mini = i;
            }
            if(nums[i] == maxele){
                maxi = i;
            }
        }
        return min((min(mini, maxi) + 1) + (n - max(mini, maxi)) , min(max(mini, maxi)+1, (n - min(mini, maxi))));
    }
};