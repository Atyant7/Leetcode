class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> ans;
        long long temp = num/3;
        if((temp-1) + (temp) + (temp+1) == num){
            ans.push_back(temp-1);
            ans.push_back(temp);
            ans.push_back(temp+1);
        }
        return ans;
    }
};