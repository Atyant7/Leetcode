class Solution {
public:
    int findMax(vector<int>& nums2, int temp){
        int ans = INT_MIN;
        int i = 0;
        for(int j = 0; j < nums2.size() ; j++){
            if(nums2[j] == temp){
                i = j+1;
                break;
            }
        }
        for(i ; i < nums2.size() ; i++){
            if(temp < nums2[i]){
                ans = nums2[i];
                break;
            }
        }
        return ans == INT_MIN ? -1 : ans;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());
        for(int i = 0; i < nums1.size(); i++){
            ans[i] = findMax(nums2, nums1[i]);
        }
        return ans;
    }
};