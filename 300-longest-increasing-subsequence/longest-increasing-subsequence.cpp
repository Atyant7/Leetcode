// dp
class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;
        vector<int> v(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    v[i] = max(v[i], v[j]+1);
                }
            }
        }
        for(int i = 0; i < v.size(); i++){
            ans = max(ans, v[i]);
        }
        return ans;
    }
};

// binary search 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i = 1; i < n; i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                auto idx = lower_bound(temp.begin(), temp.end(), nums[i]);
                if(idx == temp.end()){
                    temp.push_back(nums[i]);
                }else{
                    *idx = nums[i];
                }
            }
        }
        return temp.size();
    }
};