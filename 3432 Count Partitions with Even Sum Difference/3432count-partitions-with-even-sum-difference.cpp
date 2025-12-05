class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int ans = 0;
        int temp = 0;
        vector<int> v(nums.size() , 0);
        for(int i  = 0 ; i < nums.size() ; i++){
            temp += nums[i];
            v[i] = temp;
        }
        int j = v.size() - 1;
        for(int i = 0 ; i < v.size() - 1 ; i++){
            if((2*v[i] - v[j])%2 == 0){
                ans++;
            }
        }
        return ans;
    }
};