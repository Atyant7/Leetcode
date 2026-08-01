class Solution {
public:
    int minElement(vector<int>& nums) {
        int maxele = INT_MAX;
        for(int i = 0 ; i < nums.size() ; i++){
            int a = nums[i];
            int ok = 0;
            while(a != 0){
                ok+=(a%10);
                a = a/10;
            }
            maxele = min(maxele, ok);
        }
        return maxele;
    }
};