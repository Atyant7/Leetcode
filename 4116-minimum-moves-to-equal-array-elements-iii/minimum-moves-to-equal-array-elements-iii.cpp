class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxel = *max_element(nums.begin(), nums.end());
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            cnt += (maxel - nums[i]);
        }
        return cnt;
    }
};