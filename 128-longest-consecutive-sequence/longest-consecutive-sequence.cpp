class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int maxCount = 1;
        int n = nums.size();
        int cnt = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]+1){
                cnt++;
            }
            else if(nums[i-1] == nums[i]){
                continue;
            }
            else{
                cnt = 1;
            }
            maxCount = max(maxCount, cnt);
        }
        return maxCount;
    }
};