class Solution {
public:
    int helper(vector<int> & v, int i, int j){
        if( i == j) return v[i];
        int p1 = v[i] - helper(v, i+1, j);
        int p2 = v[j] - helper(v, i, j-1);
        return max(p1, p2);
    }
    bool predictTheWinner(vector<int>& nums) {
        if (nums.size() == 1 || nums.size() == 2) return true;
        int temp = helper(nums, 0, nums.size()-1);
        return temp >= 0;
    }
};