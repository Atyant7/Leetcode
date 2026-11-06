class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 1) return;
        int n = nums.size();
        reverse(nums.begin() + n-k % n, nums.end());
        reverse(nums.begin(), nums.begin() + n-k % n);
        reverse(nums.begin(), nums.end());
    }
};