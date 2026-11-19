class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> v (nums.begin(), nums.end());
        sort(v.begin(), v.end());
        int mid = n/2;
        int a = abs(v[n-1] - v[2]);
        int b = abs(v[0] - v[n-3]);
        int c = abs(v[n-2] - v[1]);
        return min({a, b, c});
    }
};