class Solution {
public:
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a%b);
    }
    long long gcdSum(vector<int>& nums) {
        long long n = nums.size();
        vector<int> mx(n);
        mx[0] = nums[0];
        for(int i = 1 ; i < n ; i++){
            mx[i] = max(mx[i-1] , nums[i]);
        }
        vector<int>prefix(n);
        for(int i = 0; i < n ; i++){
            prefix[i] = gcd(nums[i] , mx[i]);
        }
        sort(prefix.begin() , prefix.end());
        int i = 0 , j = n-1;
        long long ans = 0;
        while(i < j){
            ans += gcd(prefix[i] , prefix[j]);
            i++;
            j--;
        }
        return ans;
    }
};