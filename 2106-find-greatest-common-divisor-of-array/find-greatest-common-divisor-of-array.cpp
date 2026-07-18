class Solution {
public:
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a%b);
    }
    int findGCD(vector<int>& nums) {
        int min_ele = nums[0];
        int max_ele = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            min_ele = min(min_ele, nums[i]);
            max_ele = max(max_ele, nums[i]);
        }
        return gcd(min_ele, max_ele);
    }
};