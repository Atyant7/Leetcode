class Solution {
public:
    bool helper(vector<int> & v, int i, int j, int p1, int p2, int flag){
        if(i > j){
            return p1 >= p2;
        }
        if(flag == 0){
            return helper(v, i+1, j, p1+v[i], p2, 1) || helper(v, i, j-1, p1+v[j], p2, 1);
        }
        else{
            return helper(v, i+1, j, p1, p2+v[i], 0) && helper(v, i, j-1, p1, p2+v[j], 0);
        }
        return p1>=p2;
    }
    bool predictTheWinner(vector<int>& nums) {
        if (nums.size() == 1 || nums.size() == 2) return true;
        return helper(nums, 0, nums.size()-1, 0, 0, 0);
    }
};